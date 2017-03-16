package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object CongruentGenerator {

    private val FILE_NAME_SRC = "/congruent_generator_src.txt"
    private val FILE_NAME_KEY = "/congruent_generator_key.txt"
    private val FILE_NAME_ENCODE = "/congruent_generator_encode.txt"
    private val FILE_NAME_DECODE = "/congruent_generator_decode.txt"

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
        print("Enter A: ")
        val a = readLine().toString().toInt()
        print("Enter C: ")
        val c = readLine().toString().toInt()
        print("Enter m: ")
        val m = readLine().toString().toInt() % alphabet.size
        print("Enter T(0): ")
        val t0 = readLine().toString().toInt() % alphabet.size

        var key = alphabet[t0].toString()
        (0..Random().nextInt(alphabet.size)).map {
            val value = (a * alphabet.indexOf(key.last().toString()) + c) % m
            key += alphabet[value]
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