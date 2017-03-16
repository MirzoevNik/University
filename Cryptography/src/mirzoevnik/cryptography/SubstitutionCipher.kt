package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object SubstitutionCipher {

    val FILE_NAME_SRC = "/substitution_cipher_src.txt"
    val FILE_NAME_MATRIX = "/substitution_cipher_matrix.txt"
    val FILE_NAME_ENCODE = "/substitution_cipher_encode.txt"
    val FILE_NAME_DECODE = "/substitution_cipher_decode.txt"

    val SEPARATOR = "0"

    val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    val fileMatrix = File(javaClass.getResource("/").path + FILE_NAME_MATRIX)
    val fileEncode = File(javaClass.getResource("/").path + FILE_NAME_ENCODE)
    val fileDecode = File(javaClass.getResource("/").path + FILE_NAME_DECODE)

    fun createMatrix() : List<List<String>> {
        val alphabet = ArrayList<String>()
        (0..9).map { alphabet.add(it.toString()) }
        ".?,!:; ".map { alphabet.add(it.toString()) }
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }

        val countColumns = Math.round(Math.sqrt(alphabet.size.toDouble())).toInt()
        val temp = alphabet.size / countColumns
        val countRows = { if (alphabet.size % countColumns > 0) temp + 1 else temp }.invoke()
        val matrix = Array(countRows) { Array(countColumns, {
            if (alphabet.size > 0) {
                val value = alphabet[Random().nextInt(alphabet.size)]
                alphabet.remove(value)
                value
            } else {
                ""
            }
        }).toList()}.toList()
        fileMatrix.delete()
        fileMatrix.createNewFile()
        matrix.forEach {
            it.forEach { fileMatrix.appendText(it) }
            fileMatrix.appendText(System.lineSeparator())
        }
        return matrix
    }

    fun encode() {
        val matrix = createMatrix()
        fileEncode.delete()
        fileEncode.createNewFile()
        fileSrc.forEachLine {
            it.forEach {
                val symbol = it.toString()
                var row = 0
                var column = 0
                var notFound = true
                (0..matrix.size - 1).forEach {
                    val index = matrix[it].indexOf(symbol)
                    if (notFound && index > -1) {
                        row = it + 1
                        column = index + 1
                        if (row > 9) {
                            fileEncode.appendText(SEPARATOR)
                        }
                        fileEncode.appendText(row.toString())
                        if (row > 9) {
                            fileEncode.appendText(SEPARATOR)
                        }
                        if (column > 9) {
                            fileEncode.appendText(SEPARATOR)
                        }
                        fileEncode.appendText(column.toString())
                        if (column > 9) {
                            fileEncode.appendText(SEPARATOR)
                        }
                        notFound = false
                    }
                }
            }
            fileEncode.appendText(System.lineSeparator())
        }
    }

    fun decode() {
        val matrix = readMatrix()
        fileDecode.delete()
        fileDecode.createNewFile()
        fileEncode.forEachLine {
            var line = it
            var isRow = true
            var row = 0
            line.forEach {
                var value = ""
                if (line.length > 3 && line[0].toString() == SEPARATOR && line[3].toString() == SEPARATOR) {
                    value = line.substring(1, 3)
                    line = line.removePrefix(SEPARATOR + value + SEPARATOR)
                } else if (line.isNotEmpty()) {
                    value = line[0].toString()
                    line = line.removePrefix(value)
                }
                if (value.isNotEmpty()) {
                    if (isRow) {
                        row = value.toInt() - 1
                        isRow = false
                    } else {
                        fileDecode.appendText(matrix[row][value.toInt() - 1])
                        isRow = true
                    }
                }
            }
            fileDecode.appendText(System.lineSeparator())
        }
    }

    fun readMatrix() : List<List<String>> {
        val matrix = ArrayList<ArrayList<String>>()
        fileMatrix.forEachLine {
            val row = ArrayList<String>()
            it.forEach {
                row.add(it.toString())
            }
            matrix.add(row)
        }
        return matrix
    }
}