package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object KDigitAlphabet {

    private val FILE_NAME_SRC = "/k-digit_alphabet_src.txt"
    private val FILE_NAME_KEY = "/k-digit_alphabet_key.txt"
    private val FILE_NAME_ENCODE = "/k-digit_alphabet_encode.txt"
    private val FILE_NAME_DECODE = "/k-digit_alphabet_decode.txt"

    private val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    private val fileKey = File(javaClass.getResource("/").path + FILE_NAME_KEY)
    private val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    private val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    private val alphabet = ArrayList<String>()
    private var k = 0
    private var p = 0

    init {
        fileEncode.delete()
        fileDecode.delete()
        fileKey.delete()

        initAlphabet()

        print("Enter k: ")
        k = readLine().toString().toInt() % alphabet.size
        print("Enter p: ")
        p = readLine().toString().toInt()
    }

    private fun initAlphabet() {
        (0..9).map { alphabet.add(it.toString()) }
        ".?,!:; ".map { alphabet.add(it.toString()) }
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }
    }

    private fun generateKey() : String {
        val alphabetCopy = ArrayList<String>(alphabet)
        var key = ""
        (0..p).map {
            val value = alphabetCopy[Random().nextInt(alphabetCopy.size)]
            alphabetCopy.remove(value)
            key += value
        }

        fileKey.appendText(key)
        fileKey.appendText(System.lineSeparator())
        return key
    }

    fun encode() {
        fileKey.createNewFile()
        var key = generateKey()
        var currentNumber = 0
        fileEncode.createNewFile()
        fileSrc.forEachLine {
            p %= it.length
            it.forEach {
                fileEncode.appendText(getEncodedSymbol(it.toString(), key[currentNumber].toString()))
                currentNumber++
                if (currentNumber == p) {
                    currentNumber = 0
                    key = generateKey()
                }
            }
            fileEncode.appendText(System.lineSeparator())
        }
    }

    fun decode() {
        var keys = fileKey.readLines().toMutableList()
        var key = keys.first()
        var currentNumber = 0
        fileDecode.createNewFile()
        fileEncode.forEachLine {
            it.forEach {
                fileDecode.appendText(getDecodedSymbol(it.toString(), key[currentNumber].toString()))
                currentNumber++
                if (currentNumber == p) {
                    currentNumber = 0
                    keys.removeAt(0)
                    key = keys.first()
                }
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    private fun getEncodedSymbol(srcSymbol : String, keySymbol : String) : String {
        val posSrc = alphabet.indexOf(srcSymbol)
        if (posSrc != -1) {
            return alphabet[(posSrc + alphabet.indexOf(keySymbol)) % k]
        }
        return srcSymbol
    }

    private fun getDecodedSymbol(encodedSymbol : String, keySymbol : String) : String {
        var posEncoded = alphabet.indexOf(encodedSymbol)
        if (posEncoded != -1) {
            val posKeySymbol = alphabet.indexOf(keySymbol)
            while (posEncoded <= posKeySymbol) {
                posEncoded += k
            }
            return alphabet[posEncoded - posKeySymbol]
        }
        return encodedSymbol
    }
}