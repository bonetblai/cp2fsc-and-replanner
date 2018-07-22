options(width=200)
library(plyr)
data = read.csv("data.csv", header=T)
good = data[data$plan.size != -1, ]
summary = ddply(good, .(folder, family, domain.file, problem, planner), summarise,
                instance.time.N = length(instance.time),
                planner.calls.mean = mean(planner.calls),
                plan.size.mean = mean(plan.size),
                instance.time.mean = mean(instance.time),
                prep.time.mean = mean(prep.time + planner.time - planner.search.time),
                exec.time.mean = mean(instance.time - planner.time + planner.search.time)
                #time.per.planner.call.mean = instance.time.mean / planner.calls.mean
                #instance.time.sd = sd(instance.time),
                #instance.time.se = instance.time.sd / sqrt(instance.time.N)
               )
format(summary, digits=0, nsmall=2, scientific=FALSE)

