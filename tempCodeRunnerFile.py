# given data
cover_price = 24.95  # in dollars
discount_cost = 0.40
shipping_cost_first_copy = 3  # in dollars
shipping_cost_additional_copy = 0.75  # in dollars
num_of_copies = 60

# Calculating the discounted price per copy
discounted_cost_per_copy = cover_price * (1 - discount_rate)

# Calculating  the total cost for 60 copies including shipping
total_wholesale_cost = (
    (discounted_cost_per_copy + shipping_cost_first_copy) +  # Cost for the first copy
    (discounted_cost_per_copy + shipping_cost_additional_copy) * (num_of_copies - 1)  # Cost for additional copies
)
# Print the wholesale result
print("The total wholesale cost for 60 copies is $", round(total_wholesale_cost, 2))
