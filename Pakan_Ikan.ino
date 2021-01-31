#include <DS1302.h>
#include <Servo.h>
Time t;
Servo myservo;
int Hour;
int Min;
int Sec;
// Init the DS1302
DS1302 rtc(2, 3, 4);

void setup()
{
  myservo.attach(9); 
  myservo.write(45); 
  // Setting Jam Ke mode yang sedang berjalan
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(115200);
  // Baris berikut dapat diberi komentar untuk menggunakan nilai yang sudah disimpan di DS1302
  rtc.setDOW(SUNDAY); // Setel Hari-dalam-Minggu ke MINGGU
  rtc.setTime(21, 28, 9); // Setel waktu ke 12:00:00 (format 24 jam)
  rtc.setDate(1, 31, 2021); // Setel tanggal ke 31 Januari 2021
}

 void loop(){
  t = rtc.getTime();
  Hour = t.hour;
  Min = t.min;
  Sec = t.sec;
   Serial.print(Hour);
   Serial.print(":");
   Serial.print(Min);
   Serial.print(":");
   Serial.println(Sec);
  
  //atur waktu untuk memberi makan ikan
  if ((Hour== 7 && Min== 1 && Sec== 12) || (Hour== 16 && Min== 1 && Sec== 2)) {
    myservo.write(180);
    delay (1000);
    myservo.write(0);
    delay (100);
  }
}
