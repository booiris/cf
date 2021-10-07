num = 999999001
n = 1000
f = open("ini.txt","w")
f.write(str(n*2)+"\n")
for i in range(n):
    f.write(str(num)+" "+str(1)+"\n")
    f.write(str(num)+" "+str(2)+"\n") 
    num+=1
f.close()