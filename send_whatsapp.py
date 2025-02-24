import pywhatkit as kit

# Replace with your parent's phone number (include country code, e.g., +256 for Uganda)
phone_number = '+256700259998' # Change to your parent's phone number

# Define the message you want to send
message = 'Hey, I just updates my project on Github! Check it out: [your repo link].'

# Send the message at a pecific time (24-hour format, adjust as needed)
# Format: (phone_number, message, hour, minute)
kit.sendwhatmsg(phone_number, message, 10+12, 5) # Sends at 3:00 PM, change time as needed