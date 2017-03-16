package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object CaesarCipher {

    private val FILE_NAME_SRC = "/сaesar_cipher_src.txt"
    private val FILE_NAME_KEY = "/сaesar_cipher_key.txt"
    private val FILE_NAME_ENCODE = "/сaesar_cipher_encode.txt"
    private val FILE_NAME_DECODE = "/сaesar_cipher_decode.txt"

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
        (0..Random().nextInt(alphabetSize - 1)).map {
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
                fileEncode.appendText(getEncodedSymbol(it.toString(), currentNumber))
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
                fileDecode.appendText(getDecodedSymbol(it.toString(), currentNumber))
                currentNumber++
                if (currentNumber == key.length) {
                    currentNumber = 0
                }
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    private fun getEncodedSymbol(srcSymbol : String, posKeySymbol : Int) : String {
        val posSrc = alphabet.indexOf(srcSymbol)
        if (posSrc != -1) {
            return alphabet[(posSrc + posKeySymbol) % alphabet.size]
        }
        return srcSymbol
    }

    private fun getDecodedSymbol(encodedSymbol : String, posKeySymbol : Int) : String {
        var posEncoded = alphabet.indexOf(encodedSymbol)
        if (posEncoded != -1) {
            while (posEncoded <= posKeySymbol) {
                posEncoded += alphabet.size
            }
            return alphabet[posEncoded - posKeySymbol]
        }
        return encodedSymbol
    }
}