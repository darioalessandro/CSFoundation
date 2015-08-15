package cipher

/**
 * Created by darioalessandro on 8/12/15.
 */
object ShiftCipher {

  def toInt(c : Char) : Int = c - 'a'

  def toChar(int : Int) : Char = (int + 'a').toChar

  def encrypt(plain : String, k : Int) = plain.toLowerCase map { c =>  toChar((toInt(c) + k) % 26) } mkString

  def decrypt(encrypted : String, k : Int) = encrypted map { c => toChar((toInt(c) - k) % 26) } mkString

}
