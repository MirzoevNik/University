package mirzoevnik.cryptography

import java.util.*

/**
 * @author mirzoevnik
 */
class ViginerTableEng() : ViginerTable() {

    override fun getAlphabet() : List<String> {
        val alphabet = ArrayList<String>()
        ('A'..'Z').map { alphabet.add(it.toString()) }
        ('a'..'z').map { alphabet.add(it.toString()) }
        return alphabet
    }
}