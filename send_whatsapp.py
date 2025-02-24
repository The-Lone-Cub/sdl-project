import pywhatkit as kit

# Replace with your parent's phone number (include country code, e.g., +256 for Uganda)
phone_number = '+256700259998' # Change to your parent's phone number

# Define the message you want to send
message = "Hi, I've updated my Github account, please check it out [here](github.com/The-Lone-Cub/sdl-project). Thanks"

# Send the message at a pecific time (24-hour format, adjust as needed)
# Format: (phone_number, message)
kit.sendwhatmsg_instantly(phone_number, message)