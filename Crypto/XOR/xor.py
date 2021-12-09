hex_string = "f7c6c18fccc76c0fc0838fc3c64e1428da8fcd4e150ec18fcc6c1c8fdbc74e142c8fcbcaccddd6dfdb8f6b3e691f4e140ccc8fecfbe9d4fafbe99782e2eef682fcecfd9cf882f69ffad28fc4c76c1bc1c88fc1c74e142690a5"

#convert hex to char (if possible)
def hex_to_char(hex_string):
    bytes_object = bytes.fromhex(hex_string)

    s=''

    try:
        s=bytes_object.decode("utf-8")
    except:
        s='**Cannot convert to ascii!**'

    return s

# XOR hex string
def xor_hex(str1,str2):
    res=''
    for ii in range(0,len(str1),2):       
        s=str1[ii:ii+2]

        re=(hex(int(s, 16) ^ int(str2, 16)))[2:]

        if(len(re)==1):
            re='0'+re
        res+=re

    return res

# Brute Force 1 byte
for i in range(0,256):
    try:
        print(hex_to_char(xor_hex(hex_string,str(hex(i)))))

    except:
        print("Error!")


