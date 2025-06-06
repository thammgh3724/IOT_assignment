
#include "HTTP_Task.h"
HTTPClient http;
const char *serverUrl = "http://10.28.129.97:3000/api/v1/webhook";
void sendWebHook(String cardUUID, String roomUUID)
{
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    String payload =  "{\"cardUUID\":\"" + String(cardUUID) + 
                            "\",\"roomUUID\":\"" + String(roomUUID) +
                            "\"}";
    int httpResponseCode = http.POST(payload);
    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        String response = http.getString(); // Get the server response
        Serial.print("Response from server: ");
        Serial.println(response);
    }
    else
    {
        Serial.print("Error in HTTP request: ");
        Serial.println(httpResponseCode);
    }

    // Free resources
    http.end();
}
