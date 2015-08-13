import cipher._

val k = 5

val encrypted = ShiftCipher.encrypt("attack", k)

val decrypted = ShiftCipher.decrypt(encrypted, k)

