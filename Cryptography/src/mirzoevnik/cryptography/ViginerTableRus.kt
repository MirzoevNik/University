package mirzoevnik.cryptography

import java.util.*

/**
 * @author mirzoevnik
 */
class ViginerTableRus() : ViginerTable() {

    override fun getAlphabet() : List<String> {
        val alphabet = ArrayList<String>()
        ('А'..'Я').map { alphabet.add(it.toString()) }
        ('а'..'я').map { alphabet.add(it.toString()) }
        return alphabet
    }
}