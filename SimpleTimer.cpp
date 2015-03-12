SimpleTimer::SimpleTimer(const int duration){
  Start=millis();
  Duration=duration;
}

bool SimpleTimer::IsDone(){
  return (millis()-Start >= Duration);
}

bool SimpleTimer::IsDoneReset(){
  if (millis()-Start >= Duration){
    Reset();
    return 1;
  }
  return 0;
}

unsigned long SimpleTimer::Remaining(){
  return millis() - (Start+Duration);
}

void SimpleTimer::Reset(){
  Start=millis();
}
