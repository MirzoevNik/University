package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object ReplacementCipher {

    val FILE_NAME_SRC = "/replacement_cipher_src.txt"
    val FILE_NAME_ENCODE = "/replacement_cipher_encode.txt"
    val FILE_NAME_DECODE = "/replacement_cipher_decode.txt"

    val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    val dictionary = HashMap<Int, String>()

    fun init() {
        (0..9).map { dictionary.put(it, it.toString()) }
        ".?,!:; ".map { dictionary.put(dictionary.size, it.toString()) }
        ('A'..'Z').map { dictionary.put(dictionary.size, it.toString()) }
        ('a'..'z').map { dictionary.put(dictionary.size, it.toString()) }
        ('А'..'Я').map { dictionary.put(dictionary.size, it.toString()) }
        ('а'..'я').map { dictionary.put(dictionary.size, it.toString()) }
        fileEncode.delete()
        fileDecode.delete()
    }

    fun readValues() : List<Int> {
        val values = ArrayList<Int>()
        val m = dictionary.size
        values.add(m)
        var n = m - 1
        while (true) {
            print("Enter n: ")
            n = readLine().toString().toInt()
            if (checkEuclid(n, m)) {
                break
            } else {
                println("N incorrect")
            }
        }
        values.add(n)

        print("Enter k: ")
        val k = readLine().toString().toInt()
        values.add(k)

        return values
    }

    fun encode() {
        val values = readValues()
        val m = values[0]
        val n = values[1]
        val k = values[2]
        fileEncode.createNewFile()
        fileSrc.forEachLine {
            it.forEach { fileEncode.appendText("" + dictionary[(symbolCode(it) * n + k) % m]) }
            fileEncode.appendText(System.lineSeparator())
        }
    }

    fun decode() {
        val values = readValues()
        val m = values[0]
        val n = values[1]
        val k = values[2]
        fileDecode.createNewFile()
        fileEncode.forEachLine {
            it.forEach {
                var b = symbolCode(it)
                while ((b - k) % n != 0) {
                    b += m
                }

                fileDecode.appendText("" + dictionary[((b + k) / n) % m])
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    fun checkEuclid(m : Int, n : Int) : Boolean {
        var a = n
        var b = m
        while (a != b) {
            if (a > b) {
                a -= b
            } else {
                b -= a
            }
        }

        return a == 1
    }

    fun symbolCode(symbol : Char) : Int {
        return dictionary.filterValues { it == symbol.toString() }.keys.first()
    }
}