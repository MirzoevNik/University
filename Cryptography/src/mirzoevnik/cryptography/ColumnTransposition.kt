package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object ColumnTransposition {

    val FILE_NAME_SRC = "/column_transposition_src.txt"
    val FILE_NAME_KEY = "/column_transposition_key.txt"
    val FILE_NAME_ENCODE = "/column_transposition_encode.txt"
    val FILE_NAME_DECODE = "/column_transposition_decode.txt"

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
        var line = ""
        fileSrc.forEachLine {
            it.forEach { line += it }
        }

        var size = line.length
        if (size > alphabet.size) {
            size = alphabet.size / 2
        }

        val key = generateKey(size)
        var matrix = createMatrixFromLineAndSize(line, size)
        val order = getOrderFromKey(key).toMutableList()
        (0..key.length - 2).forEach {
            val index = order.indexOf(it)

            val temp = order[index]
            order[index] = order[it]
            order[it] = temp
            matrix = swapColumns(matrix, it, index)
        }

        fileEncode.createNewFile()
        matrix.forEach {
            it.forEach { fileEncode.appendText(it) }
        }
    }

    fun decode() {
        var line = ""
        fileEncode.forEachLine {
            it.forEach { line += it }
        }

        val key = fileKey.readLines().first()
        var matrix = createMatrixFromLineAndSize(line, key.length)
        val order = getOrderFromKey(key).toMutableList()
        var newMatrix = ArrayList<List<String>>()
        matrix.forEach { newMatrix.add(ArrayList<String>()) }
        (0..key.length - 1).forEach {
            newMatrix = addColumn(newMatrix, getColumn(matrix, order[it]))
        }

        fileDecode.createNewFile()
        newMatrix.forEach {
            it.forEach { fileDecode.appendText(it) }
        }
    }

    fun generateKey(size : Int) : String {
        val alphabetCopy = ArrayList<String>(alphabet)
        var key = ""
        (0..size - 1).map {
            val value = alphabetCopy[Random().nextInt(alphabetCopy.size)]
            alphabetCopy.remove(value)
            key += value
        }

        fileKey.createNewFile()
        fileKey.appendText(key)
        return key
    }

    fun getOrderFromKey(key : String) : List<Int> {
        val order = ArrayList<Int>()
        val sortedList = key.toList().sortedBy { alphabet.indexOf(it.toString()) }
        key.forEach { order.add(sortedList.indexOf(it)) }
        return order
    }

    fun createMatrixFromLineAndSize(line : String, size : Int) : List<List<String>> {
        var lineCopy = line
        val matrix = ArrayList<List<String>>()
        while (lineCopy.length >= size) {
            val subline = lineCopy.substring(0, size)
            lineCopy = lineCopy.removePrefix(subline)
            matrix.add(subline.toList().map { it.toString() })
        }
        if (lineCopy.isNotEmpty()) {
            matrix.add(lineCopy.substring(0, lineCopy.length).toList().map { it.toString() })
        }
        return matrix
    }

    fun swapColumns(matrix : List<List<String>>, first : Int, second : Int) : List<List<String>> {
        val resultMatrix = ArrayList<List<String>>()
        matrix.forEach {
            val row = it.toMutableList()
            val temp = row[first]
            row[first] = row[second]
            row[second] = temp
            resultMatrix.add(row.toList())
        }
        return resultMatrix
    }

    fun getColumn(matrix : List<List<String>>, index : Int) : List<String> {
        val resultList = ArrayList<String>()
        matrix.forEach {
            if (it.size > index) {
                resultList.add(it[index])
            }
        }
        return resultList
    }

    fun addColumn(matrix : List<List<String>>, column : List<String>) : ArrayList<List<String>> {
        val resultMatrix = ArrayList<List<String>>()
        matrix.forEachIndexed { index, row ->
            val newRow = row.toMutableList()
            if (index < column.size) {
                newRow.add(column[index])
            }
            resultMatrix.add(newRow)
        }
        return resultMatrix
    }
}