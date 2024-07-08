df = read.csv(file = "https://www.football-data.co.uk/mmz4281/2223/E0.csv"
              ,header = T)

FTHG<-df$FTHG
FTAG<-df$FTAG

# frequency table
FTHG_tbl<-table(FTHG) 
barplot(FTHG_tbl,col=1:10,xlab="Number of Goals"
        ,sub="Home Team"
        ,ylab="Frequency") # each bar represent unique catagory of data.

FTAG_tbl<-table(FTAG)
barplot(FTAG_tbl,col=1:10,xlab="Number of Goals"
        ,sub="Away Team",ylab="Frequency")

## Boxplot:

par(mfrow=c(1,2))
boxplot(FTHG,data=df,pch=20,col="orchid3",horizontal=F)
boxplot(FTAG,data=df,pch=20,col="mistyrose",horizontal=F)

# How many teams have played in EPL:
length(unique(df$HomeTeam))

# No. of goals by 'Arsenal' as HT
Ar<-subset(df,HomeTeam=='Arsenal')
sum(Ar$FTHG)

# No. of goals by 'Arsenal' as AT
Ar_a<-subset(df,AwayTeam=='Arsenal')
sum(Ar$FTAG)

# How many matches Arsenal as HT scores more than equal to 4 goals 
Ar_h<-subset(df,HomeTeam=='Arsenal')
p<-nrow(Ar_h)
Ar_h1<-subset(Ar_h,FTHG>=4)
q<-nrow(Ar_h1)

# What is the probability as HT Arsenal will scores 4 or more goals?

# Ans: Total no.of observation/total number of match q/p
#*******************************
## Quantile Concept :

#A quantile is a statistical concept that divides a dataset into 
#equal-sized portions. These portions are determined by dividing the 
#data into intervals such that each interval contains an equal proportion 
#of the data.

# Q1 represent 25th percentile of the data. 
# (Q1): 21.25 signify that 25% of data is below than 21.25 value.


# Sample dataset
data <- c(10, 15, 20, 25, 30, 35, 40, 45, 50, 55)

# Calculate quantiles
quantiles <- quantile(data,c(0.25, 0.5, 0.75))

# Print the quantiles
cat("25th percentile (Q1):", quantiles[1], "\n")
cat("50th percentile (median):", quantiles[2], "\n")
cat("75th percentile (Q3):", quantiles[3], "\n")
