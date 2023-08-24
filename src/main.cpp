#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

/**
 * Délai non bloquant
*/
class Delay
{
  private:
    /* data */
    unsigned long p_debut = millis();
    unsigned long p_duree = 0;
    unsigned long p_fin = p_debut;
  public:
    Delay(unsigned long duree);
    
    boolean EnCours();
    long Reste();
    void Relance(unsigned long duree = 0);
};

Delay::Delay(unsigned long duree)
{ 
  Relance(duree);
}

boolean Delay::EnCours()
{
  return  (millis() < p_fin);
}

long Delay::Reste()
{
  return  (p_fin - millis());
}

void Delay::Relance(unsigned long duree)
{
  p_debut = millis();
  if (duree > 0)
    p_duree = duree;
  p_fin = p_debut + p_duree;
}


