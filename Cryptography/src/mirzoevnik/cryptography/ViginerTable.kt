package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
abstract class ViginerTable {

    private val FILE_NAME_SRC = "/viginer_table_src.txt"
    private val FILE_NAME_KEY = "/viginer_table_key.txt"
    private val FILE_NAME_ENCODE = "/viginer_table_encode.txt"
    private val FILE_NAME_DECODE = "/viginer_table_decode.txt"

    private val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    private val fileKey = File(javaClass.getResource("/").path + FILE_NAME_KEY)
    private val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    private val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    protected abstract fun getAlphabet() : List<String>

    init {
        fileEncode.delete()
        fileDecode.delete()
        fileKey.delete()
        generateKey(getAlphabet())
    }

    private fun getTable() : List<List<String>> {
        val table = ArrayList<List<String>>()
        var currentList = getAlphabet().toMutableList()
        (0..currentList.size).forEach {
            table.add(currentList.toList())
            val firstSymbol = currentList.first()
            currentList.remove(firstSymbol)
            currentList.add(firstSymbol)
        }
        return table
    }


    private fun generateKey(alphabet : List<String>) : String {
        val alphabetCopy = ArrayList<String>(alphabet)
        val alphabetSize = alphabetCopy.size
        var key = ""
        (0..Random().nextInt(alphabetSize)).map {
            val value = alphabetCopy[Random().nextInt(alphabetCopy.size)]
            alphabetCopy.remove(value)
            key += value
        }

        fileKey.createNewFile()
        fileKey.appendText(key)
        return key
    }

    fun encode() {
        val key = fileKey.readLines().first()
        var currentNumber = 0
        fileEncode.createNewFile()
        fileSrc.forEachLine {
            it.forEach {
                fileEncode.appendText(getEncodedSymbol(it.toString(), key[currentNumber].toString()))
                currentNumber++
                if (currentNumber == key.length) {
                    currentNumber = 0
                }
            }
            fileEncode.appendText(System.lineSeparator())
        }
    }

    fun decode() {
        val key = fileKey.readLines().first()
        var currentNumber = 0
        fileDecode.createNewFile()
        fileEncode.forEachLine {
            it.forEach {
                fileDecode.appendText(getDecodedSymbol(it.toString(), key[currentNumber].toString()))
                currentNumber++
                if (currentNumber == key.length) {
                    currentNumber = 0
                }
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    private fun getEncodedSymbol(srcSymbol : String, keySymbol : String) : String {
        val table = getTable()
        table.forEach {
            if (it.first() == srcSymbol) {
                it.forEachIndexed { index, symbol ->
                    if (table.first()[index] == keySymbol) {
                        return symbol
                    }
                }
            }
        }
        return srcSymbol
    }

    private fun getDecodedSymbol(encodedSymbol : String, keySymbol : String) : String {
        val table = getTable()
        val column = table.first().indexOf(keySymbol)
        table.forEach {
            if (it[column] == encodedSymbol) {
                return it.first()
            }
        }
        return encodedSymbol
    }
}