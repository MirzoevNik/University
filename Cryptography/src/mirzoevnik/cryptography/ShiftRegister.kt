package mirzoevnik.cryptography

import java.io.File
import java.util.*

/**
 * @author mirzoevnik
 */
object ShiftRegister {

    private val FILE_NAME_SRC = "/shift_register_src.txt"
    private val FILE_NAME_KEY = "/shift_register_key.txt"
    private val FILE_NAME_ENCODE = "/shift_register_encode.txt"
    private val FILE_NAME_DECODE = "/shift_register_decode.txt"

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
    }

    private fun initAlphabet() {
        (0..9).map { alphabet.add(it.toString()) }
        ".?,!:; ".map { alphabet.add(it.toString()) }
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }
    }

    private fun generateKey(alphabet : List<String>, size : Int) : String {
        var key = ""
        (0..size).map {
            var initSeq = 1
            (1..Random().nextInt(size - 1) + 1).map {
                if (Random().nextBoolean()) {
                    initSeq = initSeq.shl(1) + 0b1
                } else {
                    initSeq = initSeq.shl(1) + 0b0
                }
            }

            var keySymbolPosition = 1
            val bitsSize = Random().nextInt(size) + 1
            while(countBits(keySymbolPosition) < bitsSize) {
                val currentSeqSize = countBits(initSeq)
                val lastBit = initSeq.xor(initSeq.shr(1).shl(1) + 0b0)
                val secondBit = initSeq.shr(currentSeqSize - 2).xor(0b10)
                initSeq = 1.shl(currentSeqSize)
                            .or(lastBit.xor(secondBit).shl(currentSeqSize - 1))
                            .or(initSeq.xor(1.shl(currentSeqSize - 1)))
                keySymbolPosition = keySymbolPosition.shl(1).or(lastBit)
            }

            key += alphabet[keySymbolPosition % alphabet.size]
        }

        fileKey.createNewFile()
        fileKey.appendText(key)
        return key
    }

    private fun countBits(bitSequence : Int) : Int {
        var copyBitSequence = bitSequence
        var result = 0
        while(copyBitSequence != 0) {
            copyBitSequence = copyBitSequence.shr(1)
            result++
        }
        return result
    }

    fun encode() {
        fileEncode.createNewFile()
        fileSrc.forEachLine {
            val key = generateKey(alphabet, it.length)
            var currentNumber = 0
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