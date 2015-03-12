SimpleTimer::SimpleTimer(const int duration){
  Start=millis();
  Duration=duration;
}

SimpleTimer::IsDone(){
  return (millis()-Start >= Duration);
}

SimpleTimer::IsDoneReset(){
  if (millis()-Start >= Duration){
    Reset();
    return 1;
  }
  return 0;
}

SimpleTimer::Remaining(){
  return millis() - (Start+Duration);
}

SimpleTimer::Reset(){
  Start=millis();
}
