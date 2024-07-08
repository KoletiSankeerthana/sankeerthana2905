#Dataset
?mtcars

head(mtcars)#first 6 cars

tail(mtcars)#last 6 cars
dim(mtcars)
names(mtcars)
rownames(mtcars)
mtcars$mpg
mtcars$carb
mean(mtcars$mpg)
sort(mtcars$mpg)
median(mtcars$mpg)
summary(mtcars)
max(mtcars)
min(mtcars$mpg)
rownames(mtcars)[which.max((mtcars$mpg))]
rownames(mtcars)[which.min((mtcars$mpg))]
a=(mtcars$mpg)
g<-subset(mtcars,mtcars$gear==4)
g
length(g)
m<-subset(mtcars,mtcars$am==1)
m
length(m)
a<-subset(mtcars,mtcars$am==0)
a
length(a)
p<-subset(mtcars,mtcars$mpg>21.0 & mtcars$mpg<16.0)
p
length(p)
table(mtcars$gear)
w=table(mtcars$gear)
t=as.data.frame(w)
names(t)[1]='gear'
names(t)[2]='freq'
t