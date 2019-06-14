Amag <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_AMagnitude.csv", head = FALSE)

plot(Amag$V1,Amag$V2)

plot(Amag$V1,Amag$V2,xlab="Frequency (Hz)",ylab="Voltage (V) Magnitude",col="red",main="Frequency vs. Voltage", type = "b")



Aphase <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_APhase.csv", head = FALSE)
plot(Aphase$V1,Aphase$V2,xlab="Frequency (Hz)",ylab="Phase Angle",col="red",main="Frequency vs. Phase", type = "b")



bmag <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_BMagnitude.csv", head = FALSE)
plot(bmag$V1,bmag$V2,xlab="Frequency (Hz)",ylab="Voltage (V) Magnitude",col="red",main="Frequency vs. Voltage", type = "b")





Bphase <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_BPhase.csv", head = FALSE)
plot(Bphase$V1,Bphase$V2,xlab="Frequency (Hz)",ylab="Phase Angle",col="red",main="Frequency vs. Phase", type = "b")





cmag <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_CMagnitude.csv", head = FALSE)
plot(cmag$V1,cmag$V2,xlab="Frequency (Hz)",ylab="Voltage (V) Magnitude",col="red",main="Frequency vs. Voltage", type = "b")





cphase <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_CPhase.csv", head = FALSE)
plot(cphase$V1,cphase$V2,xlab="Frequency (Hz)",ylab="Phase Angle",col="red",main="Frequency vs. Phase", type = "b")

#Measurements
measurements <- read.csv("C:\\Users\\Chris Badolato\\Desktop\\networksAndSystems\\Lab9\\lab9\\lab9_Measurements.csv", head = FALSE)


plot(measurements$V1,measurements$V6,xlab="Frequency (Hz)",ylab="Voltage (V) Magnitude",col="red",main="Measured Frequency vs. Voltage", type = "b")

plot(measurements$V1,measurements$V7,xlab="Frequency (Hz)",ylab="Phase Angle",col="red",main="Measured Frequency vs. Phase", type = "b")

