package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object CodingXOR {

    private val FILE_NAME_SRC = "/xor_coding_src.txt"
    private val FILE_NAME_KEY = "/xor_coding_key.txt"
    private val FILE_NAME_ENCODE = "/xor_coding_encode.txt"
    private val FILE_NAME_DECODE = "/xor_coding_decode.txt"

    private val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    private val fileKey = File(javaClass.getResource("/").path + FILE_NAME_KEY)
    private val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    private val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    private val alphabet = ArrayList<String>()

    init {
        fileEncode.delete()
        fileDecode.delete()
        fileKey.delete()
        initAlphabet()
        generateKey(alphabet)
    }

    private fun initAlphabet() {
        (0..9).map { alphabet.add(it.toString()) }
        ".?,!:; ".map { alphabet.add(it.toString()) }
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }
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
                fileEncode.appendText(getXOR(it.toString(), key[currentNumber].toString()))
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
                fileDecode.appendText(getXOR(it.toString(), key[currentNumber].toString()))
                currentNumber++
                if (currentNumber == key.length) {
                    currentNumber = 0
                }
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    private fun getXOR(srcSymbol : String, keySymbol : String) : String {
        val posSrc = alphabet.indexOf(srcSymbol)
        val posKey = alphabet.indexOf(keySymbol)
        val posResult = posSrc.xor(posKey)
        if (posResult < alphabet.size) {
            return alphabet[posResult]
        }
        return srcSymbol
    }
}