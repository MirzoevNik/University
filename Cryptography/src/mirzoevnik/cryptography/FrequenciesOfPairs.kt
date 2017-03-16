package mirzoevnik.cryptography

import java.io.File
import java.text.DecimalFormat
import java.util.*

/**
 * @author mirzoevnik
 */
object FrequenciesOfPairs {

    val FILE_NAME_SRC = "/frequencies_of_pairs_src.txt"
    val FILE_NAME_RESULT = "/frequencies_of_pairs_result.txt"

    val fileSrc = File(javaClass.getResource(FILE_NAME_SRC).toURI())
    val fileResult = File(javaClass.getResource("/").path + FILE_NAME_RESULT)

    fun tableOfFrequencies() {
        val table = HashMap<String, Double>()
        var count = 0
        fileSrc.forEachLine {
            it.forEachIndexed { index, value ->
                if (index > 0) {
                    val key = it[index - 1] +  value.toString()
                    if (table.contains(key)) {
                        table.replace(key, table[key]?.plus(1))
                    } else {
                        table.put(key, 1.0)
                    }
                    count++
                }
            }
        }

        fileResult.delete()
        fileResult.createNewFile()
        table.mapValues { it.value / count }.forEach {
            val line = "" + it.key + ": " + DecimalFormat("0.000").format(it.value)
            println(line)
            fileResult.appendText(line + System.lineSeparator())
        }
    }
}