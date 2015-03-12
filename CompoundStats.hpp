class StatClass{
private:
  float lowerBound;
  float upperBound;
  float midPoint;
  long frequency;
public:
  StatClass(float lb, float ub);
  long getLowerBound();
  long getUpperBound();
  long getFrequency();
  float getMidPoint();
  float getSum();
  bool ValueBelongs(float val);
  bool ValueBelongsAdd(float val);
  void Add(int value);
};


class CompoundStats{
private:
  long valueCount;    //<-- init on construction
  long classCount;    //<-- receive on construction
  float classWidth;   //<-- calculate on construction
  float minVal;       //<-- receive on construction
  float maxVal;       //<-- receive on construction
  StatClass** classes;
public:
  CompoundStats(float MinVal, float MaxVal, int ClassCount);
  ~CompoundStats();
  void AddStat(float value);
  float Mean();
  float Median();
  float Mode();
  float MeanDeviation();
  float Variance();
  float StandarDeviation();
};
