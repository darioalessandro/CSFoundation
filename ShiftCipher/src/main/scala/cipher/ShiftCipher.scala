package cipher

/**
 * Created by darioalessandro on 8/12/15.
 */
object ShiftCipher {

  def encrypt(plain : String, k : Int) = plain map { c => ( c + k % 26).toChar } mkString

  def decrypt(encrypted : String, k : Int) = encrypted map { c => ( c - k % 26).toChar } mkString

}
