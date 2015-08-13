import cipher._

val k = 3

val encrypted = ShiftCipher.encrypt("metallIca $$##234234", k)

val decrypted = ShiftCipher.decrypt(encrypted, k)

