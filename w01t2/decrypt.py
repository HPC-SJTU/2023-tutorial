from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from config import KEY_BYTE_CNT

key = get_random_bytes(KEY_BYTE_CNT).zfill(16)

file_in = open("secret.bin", "rb")
tag, nonce, ciphertext = [ file_in.read(x) for x in (16, 16, -1) ]
file_in.close()

# let's assume that the key is somehow available again
cipher = AES.new(key, AES.MODE_GCM, nonce=nonce)
data = cipher.decrypt_and_verify(ciphertext, tag)

print(data.decode())
