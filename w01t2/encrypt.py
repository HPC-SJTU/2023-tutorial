from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from plaintext import plaintext
from config import KEY_BYTE_CNT

key = get_random_bytes(KEY_BYTE_CNT).zfill(16)
print(key)
cipher = AES.new(key, AES.MODE_GCM)
ciphertext, tag = cipher.encrypt_and_digest(plaintext.encode())

with open("secret.bin", "wb") as file_out:
    [ file_out.write(x) for x in (tag, cipher.nonce, ciphertext) ]

