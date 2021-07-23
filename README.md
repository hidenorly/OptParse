# OptParse

C++20 based OptParser

```
int main(int argc, char **argv)
{
  std::vector<OptParse::OptParseItem> options;

  options.push_back( OptParse::OptParseItem("-r", "--samplingRate", true, "48000", "Set Sampling Rate"));
  options.push_back( OptParse::OptParseItem("-e", "--encoding", true, "PCM16", "Set Encoding PCM8, PCM16, PCM24, PCM32, PCMFLOAT"));
  options.push_back( OptParse::OptParseItem("-c", "--channel", true, "2", "Set channel 2, 2.1, 4, 4.1, 5, 5.1, 5.1.2, 7.1"));

  OptParse optParser( argc, argv, options );

  for( auto& [anOption, anOptionValue] : optParser.values ){
    std::cout << anOption << "=" << anOptionValue << std::endl;
  }
}
```