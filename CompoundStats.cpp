StatClass::StatClass(float lb, float ub){
  lowerBound = lb;
  upperBound = ub;
  midPoint = lb+ub/2;
  frequency=0;
}

long StatClass::getLowerBound(){
  return lowerBound;
}

long StatClass::getUpperBound(){
  return upperBound;
}

long StatClass::getFrequency(){
  return frequency;
}

float StatClass::getMidPoint(){
  return midPoint;
}

float StatClass::getSum(){
  return frequency *midPoint;
}

bool StatClass::ValueBelongs(float val){
  //Checks if val belongs to [lb,ub)
  return val<upperBound && val>=lowerBound;
}

bool StatClass::ValueBelongsAdd(float val){
  if (ValueBelongs(val)){
    Add(val);
    return 1;
  }
  return 0;
}

void StatClass::Add(int value){
  frequency++;
}



CompoundStats::CompoundStats(float MinVal, float MaxVal, int ClassCount){
    minVal=MinVal;
    maxVal=MaxVal;
    classCount=ClassCount;
    classWidth = (maxVal-minVal)/classCount;
    valueCount = 0;


    //init classes
    classes = (StatClass**) malloc(sizeof(StatClass*) * classCount);
    float lb=minVal,ub;
    for(int i=0; i<classCount; i++){
      ub = lb+classWidth;
      classes[i] = (new StatClass(lb,ub));
      lb=ub;
    }
  }

CompoundStats::~CompoundStats(){
  for(int i=0; i<classCount; i++)
    delete classes[i];
  free(classes);
}

void CompoundStats::AddStat(float value){
  for(int i =0; i< classCount; i++)
    if (classes[i]->ValueBelongsAdd(value))
      break;
  valueCount++;
}

float CompoundStats::Mean(){
  float sum=0;
  for(int i =0; i< classCount; i++){
    sum += classes[i]-> getSum();
  }
  return sum/valueCount;
}

float CompoundStats::Median(){
  // the median group is the one whose accumulated freq (sum of freqs of groups before)
  // would be the first one thats bigger than n/2 (half the entries)
  float n2 = valueCount/2;
  float accFreq=0, prevAccFreq=0, freq=0;

  for(int i = 0; i < classCount; i++){
    prevAccFreq = accFreq;
    freq = classes[i]->getFrequency();
    accFreq += freq;

    if(accFreq>n2){
      float lowerBound = classes[i]->getLowerBound();
      return lowerBound + ( ( (n2 - prevAccFreq) /freq) * classWidth);
    }
  }

  Serial.print("WTF!!!");
  return 0.0f;
}

float CompoundStats::Mode(){
  //the modal group is the one whose freq is higher
  //TODO: implement
}

float CompoundStats::MeanDeviation(){
//TODO: implement
}

float CompoundStats::Variance(){
//TODO: implement
}

float CompoundStats::StandarDeviation(){
//TODO: implement
}
