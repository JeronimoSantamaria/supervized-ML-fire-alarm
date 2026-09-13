import csv
from datetime import datetime
import serial

PORT = "COM7"
BAUD_RATE = 9600
CSV_FILE = "./testing/csv_data_saving/csv/sensor_data.csv"

ser = serial.Serial(PORT, BAUD_RATE, timeout=1)

print(f"Listening on {PORT} at {BAUD_RATE} baud...")
print("Press Ctrl+C to stop.\n")

with open(CSV_FILE, "a", newline="") as file:
    writer = csv.writer(file)

    if file.tell() == 0:
        writer.writerow([
            "timestamp",
            "gas_raw",
            "temperature_c",
            "humidity_percent"
        ])

    try:
        while True:
            line = ser.readline().decode("ascii", errors="ignore").strip()

            if not line:
                continue

            print(f"Received: {line}")

            try:
                gas, temperature, humidity = line.split(",")

                gas = int(gas)
                temperature = float(temperature)
                humidity = float(humidity)

                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

                writer.writerow([
                    timestamp,
                    gas,
                    temperature,
                    humidity
                ])

                file.flush()

            except ValueError:
                print(f"Invalid sensor data: {line}")

    except KeyboardInterrupt:
        print("\nStopping...")

    finally:
        ser.close()
        print("Serial connection closed.")
