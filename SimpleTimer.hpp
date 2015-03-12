class SimpleTimer
{
private:
  unsigned long Start;
  unsigned long Duration;
public:
  SimpleTimer(const int duration);
  bool IsDone();
  bool IsDoneReset();
  unsigned long Remaining();
  void Reset();
};
