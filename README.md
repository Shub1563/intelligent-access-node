# intelligent-access-node
Intelligent Access Node 🔐

📌 Overview

The Intelligent Access Node is an embedded system-based security project that uses a keypad-based authentication mechanism to control access. The system verifies a 4-digit password and controls a servo motor to simulate door locking and unlocking.

🎯 Features

- Secure PIN-based authentication
- Real-time input using 4x4 keypad
- Servo-controlled locking mechanism
- LED indicators for status (Access Granted / Denied)
- Serial monitoring for debugging

🛠️ Components Used

- Arduino UNO
- 4x4 Keypad
- Servo Motor
- LEDs (Red & Green)
- Connecting Wires

🔌 Working Principle

1. User enters a 4-digit PIN via keypad
2. System compares entered PIN with stored password
3. If correct:
   - Green LED turns ON
   - Servo rotates to unlock
   - After 3 seconds, system relocks
4. If incorrect:
   - Red LED turns ON
   - Access is denied

📂 Project Structure

- "code/" → Arduino source code
- "images/" → Circuit diagram and simulation screenshots
- "video/" → Simulation demo video

🖼️ Simulation Preview

This project is designed and tested using Tinkercad simulation.

🚀 Future Improvements

- RFID-based authentication
- IoT-based remote access control
- Mobile app integration
- Password change feature

👨‍💻 Author

Shubham Yadav
