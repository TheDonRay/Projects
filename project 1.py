#My own program (side thing)
#Program is about the idea that it can tell you the amount of time it will take
#to save up for that given goal value you want.


value_of_item_you_want = input("Enter the value of the item you want to save up for:" )
num = int(value_of_item_you_want)



income = input("Do you have weekly, Biweekly, or Monthly Income?: ")
income_amount: int = 0
if income == "weekly":
    income_amount = (int(input("Enter your weekly income amount: ")))
elif income == "Biweekly":
    income_amount = (int(input("Enter your Biweekly income: ")))
elif income == "Monthly":
    income_amount = (int(input("Enter your Monthly Income: ")))
else:
    if income == (" "):
        print(input("Invalid input"))

#Gotta figure out the math 

getq = num // income_amount
print("The number of years it will take would be: ",getq) 




#divding = num/income
#print("The amount of time it will take will be: ",dividing)




#So the math behind this is that whaatever the value entered we can do that number / the amount of income. 
