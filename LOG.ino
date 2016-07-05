void logData() {

  timestamp = getTimestamp();
  int sensor1 = analogRead(A0);
  int sensor2 = analogRead(A1);
  int sensor3 = analogRead(A2);
  Serial.println(timestamp);
  logfile.print(timestamp); logfile.print(",");
  logfile.print(sensor1); logfile.print(",");
  logfile.print(sensor2); logfile.print(",");
  logfile.println(sensor3);
  logfile.flush();
  if (logfile.size() > 10000000) { // if filesize is more than 10M then create a new file
    logfile.close();
    stage = NEW;
  }
  digitalWrite(SD_LED, HIGH);
  delay(40);
  digitalWrite(SD_LED, LOW);
}
