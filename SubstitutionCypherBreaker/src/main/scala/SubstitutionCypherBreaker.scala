/**
 * Created by darioalessandro on 8/12/15.
 */
object SubstitutionCypherBreaker {

  def decrypt(encrypted : String) : String = {
    var lettersMap : Map[Char, Float] = lettersDB
    val encryptedLength = encrypted.length

    for{ letter <- encrypted.replace(" ", "") } yield {
      val inc = lettersMap(letter) + 1f
      lettersMap = lettersMap + (letter -> inc)
    }

    val frequencies = for {letter <- lettersMap} yield {(letter._1,letter._2/encryptedLength)}

    val replacementMap = for{(charFreq, actual) <- frequencies; (prob,charProb) <- probabilities if actual >= prob * 0.90 && actual <= prob * 1.1} yield (charFreq, charProb)

    for(letter <- encrypted) yield {
      replacementMap.getOrElse(letter,letter)
    }
  }

  def probabilities : Map[Float,Char] = Map(
    0.0817f -> 'a',
    0.0150f -> 'b',
    0.0278f -> 'c',
    0.0425f -> 'd',
    0.1270f -> 'e',
    0.0223f -> 'f',
    0.0202f -> 'g',
    0.0609f -> 'h',
    0.0697f -> 'i',
    0.0015f -> 'j',
    0.0077f -> 'k',
    0.0403f -> 'l',
    0.0241f -> 'm',
    0.0675f -> 'n',
    0.0751f -> 'o',
    0.0193f -> 'p',
    0.0010f -> 'q',
    0.0599f -> 'r',
    0.0633f -> 's',
    0.0906f -> 't',
    0.0276f -> 'u',
    0.0098f -> 'v',
    0.0236f -> 'w',
    0.0015f -> 'x',
    0.0197f -> 'y',
    0.0007f -> 'z'
  )

  def lettersDB : Map[Char, Float] = {
    val tupples = for { letter <- 'a' to 'z'} yield {(letter, 0f)}
    tupples.toMap
  }

  def main (args: Array[String]) {
    val encrypted = "giuifg cei iprc tpnn du cei qprcni"
    val e = decrypt(encrypted)
    println(s"decrypted $e")
  }

}
