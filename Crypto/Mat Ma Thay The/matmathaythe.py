listCharacter = ["A","B",'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

Message = "HELLOWHATAREYOUDOINGSCTF"  
Ciphertext = "PYZZCSPFKFEYJCQACBHXGDKW"

MessageResult = []
for i in range(0,26):
    MessageResult.append("")

for i in range(0,len(Message)) :
    index = listCharacter.index(Message[i])
    MessageResult[index] = Ciphertext[i]

print(MessageResult)

output= ""
Ciphertext2 = "KPBGSFGQGYABHSFE"
for i in range(0,len(Ciphertext2)) :
    char = Ciphertext2[i]
    index=  MessageResult.index(char)
    output = output + listCharacter[index]
print(output)  