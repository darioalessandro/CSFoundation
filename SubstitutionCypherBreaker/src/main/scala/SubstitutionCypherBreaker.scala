/**
 * Created by darioalessandro on 8/12/15.
 */
object SubstitutionCypherBreaker {

  def probabilities(scale : Float) : Map[Float,Char] = Map(
    0.0817f * scale -> 'a',
    0.0150f * scale -> 'b',
    0.0278f * scale -> 'c',
    0.0425f * scale -> 'd',
    0.1270f * scale -> 'e',
    0.0223f * scale -> 'f',
    0.0202f * scale -> 'g',
    0.0609f * scale -> 'h',
    0.0697f * scale -> 'i',
    0.0015f * scale -> 'j',
    0.0077f * scale -> 'k',
    0.0403f * scale -> 'l',
    0.0241f * scale -> 'm',
    0.0675f * scale -> 'n',
    0.0751f * scale -> 'o',
    0.0193f * scale -> 'p',
    0.0010f * scale -> 'q',
    0.0599f * scale -> 'r',
    0.0633f * scale -> 's',
    0.0906f * scale -> 't',
    0.0276f * scale -> 'u',
    0.0098f * scale -> 'v',
    0.0236f * scale -> 'w',
    0.0015f * scale -> 'x',
    0.0197f * scale -> 'y',
    0.0007f * scale -> 'z'
  )

  def decrypt(encrypted : String) : String = {
    var lettersMap : Map[Char, Float] = lettersDB
    val encryptedLength = encrypted.length

    for{ letter <- encrypted.replace(" ", "") } yield {
      val inc = lettersMap(letter) + 1f
      lettersMap = lettersMap + (letter -> inc)
    }

    val frequencies = for {letter <- lettersMap} yield {(letter._1,letter._2/encryptedLength)}

    val eFreq = frequencies.maxBy(f => f._2)._2 / 0.1270f

    val probabilities  : Map[Float,Char] = this.probabilities(eFreq)

    val replacementMap = for{ (charFreq, actual) <- frequencies
                              (prob,charProb) <- probabilities
                              if actual >= prob * 0.90 && actual <= prob * 1.1}
                         yield (charFreq, charProb)

    for(letter <- encrypted) yield {
      replacementMap.getOrElse(letter,letter)
    }
  }

  def lettersDB : Map[Char, Float] = {
    val tupples = for { letter <- 'a' to 'z'} yield {(letter, 0f)}
    tupples.toMap
  }

  def main (args: Array[String]) {
    val encrypted = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndt wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb"
    val e = decrypt(encrypted)
    println(s"decrypted $e")
  }

}
