package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object DoublesCipher {

    val FILE_NAME_SRC = "/doubles_cipher_src.txt"
    val FILE_NAME_KEY = "/doubles_cipher_key.txt"
    val FILE_NAME_ENCODE = "/doubles_cipher_encode.txt"
    val FILE_NAME_DECODE = "/doubles_cipher_decode.txt"

    val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    val fileKey = File(javaClass.getResource("/").path + FILE_NAME_KEY)
    val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    val alphabet = ArrayList<String>()

    fun init() {
        (0..9).map { alphabet.add(it.toString()) }
        ".?,!:; ".map { alphabet.add(it.toString()) }
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }
        fileEncode.delete()
        fileDecode.delete()
        fileKey.delete()
    }

    fun encode() {
        val pairs = getPairs(generateKey())

        fileEncode.createNewFile()
        fileSrc.forEachLine {
            it.forEach { fileEncode.appendText("" + getPair(pairs, it.toString())) }
            fileEncode.appendText(System.lineSeparator())
        }
    }

    fun decode() {
        val pairs = getPairs(fileKey.readLines().first())

        fileDecode.createNewFile()
        fileEncode.forEachLine {
            it.forEach { fileDecode.appendText("" + getPair(pairs, it.toString())) }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    fun generateKey() : String {
        val alphabetCopy = ArrayList<String>(alphabet)
        val alphabetSize = alphabetCopy.size
        var key = ""
        (0..alphabetSize / 2).map {
            val value = alphabetCopy[Random().nextInt(alphabetCopy.size)]
            alphabetCopy.remove(value)
            key += value
        }

        fileKey.createNewFile()
        fileKey.appendText(key)
        return key
    }

    fun getPairs(key : String) : Map<String, String> {
        val keys = key.toList().map { it.toString() }
        val values = ArrayList<String>(alphabet)
        values.removeAll(keys)
        val pairs = HashMap<String, String>()
        keys.map {
            var value = it
            if (values.isNotEmpty()) {
                value = values.first()
                values.remove(value)
            }
            pairs.put(it, value)
        }
        return pairs
    }

    fun getPair(pairs : Map<String, String>, value : String) : String {
        return pairs.getOrElse(value, { pairs.filter { it.value == value }.keys.first() })
    }
}