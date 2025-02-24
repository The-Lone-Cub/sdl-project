import pywhatkit as kit

# Replace with your parent's phone number (include country code, e.g., +256 for Uganda)
phone_number = PHONE_NUMBER # Change to your parent's phone number

# Define the message you want to send
message = MESSAGE

# Send the message at a pecific time (24-hour format, adjust as needed)
# Format: (phone_number, message)
kit.sendwhatmsg_instantly(phone_number, message)