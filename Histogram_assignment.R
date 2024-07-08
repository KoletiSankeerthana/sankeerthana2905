# What is Histogram :

# A histogram is a graphical representation of the distribution of data, 
# showing the frequency or relative frequency of each data category (or bin) in a dataset. 
# It is a way to represent the underlying frequency distribution of a set of continuous 
# data.


# Understand the histogram concept with the help of an example:

# Suppose there are 30 students in a class. Now i want to know if i pick up randomly any student what will be the 
# probability that his/her height will be within 150cm-170cm. or we can say P(150<x<170).
# We can achieve our goal using histogram.

# Step 1: [collecting the Data]

# Sample data: student heights in centimeters
ht_cm <- c(158.4, 162.7, 165.3, 160.4, 170.6, 173.0, 168.3, 158.2, 162.1, 168.8, 
           175.9, 178.2, 170.3, 165.5, 160.8, 158.4, 162.6, 168.5, 173.1, 170.4, 
           173.5, 175.7, 178.2, 180.6, 170.9, 165.4, 162.3, 160.2, 168.1, 173.7)

# Step 2 :creating buckets:
min(ht_cm)
max(ht_cm)
bins <- seq(155,185 , by = 5)  # Define bins with a width of 5 cm

# Step 3: [Calculate frequency density]

freq <- table(cut(ht_cm, breaks = bins, include.lowest = TRUE)) # define frequencies or count in each bins

bin_width <- diff(bins)[1]  # Calculate the bin width

density_values <- freq/ (sum(freq) * bin_width) 
# calculate density i,e.[density = (relative freq)/width]

# Step 4:[storing the density value in the relative bucket]

x=seq(155,185,by=0.1) # define x-scale
dx=c(rep(NA,length(x))) # define a vector in the length of x

# storing the density value in the relative bucket 
for(i in 2:length(bins)){
  dx[x>bins[i-1] & x<=bins[i]]=density_values[i-1]
}

dx[1]=0;dx[length(x)]=0 # manually keeping 0 in the first & last value of dx.

# Step 5:[plot the histogram]

par(mfrow=c(1,2)) # par function used to set graphical parameters for plots.
plot(x,dx,type = "l",xlim=c(155,185),ylim=c(0,0.075))
#abline(h=0)

# Step 6 :[using hist function]
hist_obj<-hist(ht_cm, main = "Histogram of Student Heights (cm)"
               , xlab = "Height (cm)"
               , ylab = "Number of Students"
               , probability = T,ylim=c(0,0.075))

# As we can see that our plotting and the hist function is giving same result.It is clear how the histogram function is working.

probability<-(sum(density_values)*bin_width)
print(probability)