listCharacter = ["A","B",'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']


plaintext = "HELLOWORLDCRYPTOGRAPHERS"
ciphertext= "HRNTSJHTTSJVPHTFKRWTZSDW"
output =""

for i in range(0,len(plaintext)):
    gt =  (26 + listCharacter.index(ciphertext[i]) - listCharacter.index(plaintext[i]))%26
    #print(gt)
    char = listCharacter[gt]
    output = output + char
print(output) 

  

  