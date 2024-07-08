attach(mtcars)
summary(mtcars)

#step1 : sorting the dataset

mpg1 <- mpg
s <- sort(mpg1)
#even number of values hence don't add 1
#odd number of values then add 1 before dividing by 2 while finding median
q2 = (length(s))/2
Q2 = s[q2]
Q2
q1 = (length(s))/4
Q1 = s[q1]
q3 = (length(s)) * (3/4)
Q3 = s[q3]

#for a continuous variable when dataset gets larger then n and n+1 doesn't make a difference

#general elections in 2019

vote_share <- c(37.36,19.49,4.07,3.63,2.55,2.53,2.26,2.1 ,2.04)
sum(vote_share)

names(vote_share) = c("BJP", "INC", "AITC", "BSP", "SP", "YSRP", "DMK", "ShivSena", "TDP")
seat_share <- c(303,52,22,10,5,23,23,18,3)
names(seat_share) = names(vote_share)

vote_share['others'] = 100 - sum(vote_share)
seat_share['others'] = 545 - sum(seat_share)

#add points to a plot
plot(vote_share, seat_share, pch = 20, ylab = "No of seats", xlab = "Percentage of votes")
grid()

#fit the line: seat_share = a + b*vote_share 

mod = lm(seat_share ~ vote_share)
#lm function accomodate the minimum error and gives coefficient a and b 
#seat_share is y and vote_share is x
abline(mod, col = "red", lwd = 2 )

summary(mod)
#a=-11.178,b=6.568,BJP vote_share 37.3,what will be BJP seat_share
a=coef(mod)[1]
b=coef(mod)[2]

Y_hat=a+b*37.5
Y_hat=235

# error=y_hat-Y(true)=235-303=

# try quadraric model in our data:y=a+bx+cx^2

#seat_share=a2+b2*vote_share+c2*vote_share^2
mod2=lm(seat_share~vote_share+I(vote_share^2))

a2=coef(mod2)[1]
b2=coef(mod2)[2]
c2=coef(mod2)[3]
#with 37.3 vote share what will be BJP seat share?

Y_hat2 = a2+b2*37.3+c2*(37.3)^2
Y_hat2 #300.3817 less error so quadratic model is better. Fitting model because data is continuous if discrete then don't use lm

#if BJP vote share increase by 40% what will be its seat share?BJP will get 357.7601 seats

Y_hat3 = a2+b2*40+c2*(40)^2
Y_hat3
