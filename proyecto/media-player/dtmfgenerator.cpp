#include "dtmfgenerator.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

namespace little_endian_io
{
  template <typename Word>
  std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
  {
    for (; size; --size, value >>= 8)
      outs.put( static_cast <char> (value & 0xFF) );
    return outs;
  }
}
using namespace little_endian_io;

DtmfGenerator::DtmfGenerator()
{

}

void DtmfGenerator:: generateTone(int f1,int f2,string name){
      ofstream f( name, ios::binary );
      // Write the file headers
      f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
      write_word( f,     16, 4 );  // no extension data
      write_word( f,      1, 2 );  // PCM - integer samples
      write_word( f,      2, 2 );  // two channels (stereo file)
      write_word( f,   8000, 4 );  // samples per second (Hz)
      write_word( f,  32000, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
      write_word( f,      4, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
      write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)

      // Write the data chunk header
      size_t data_chunk_pos = f.tellp();
      f << "data----";  // (chunk size to be filled in later)

      // Write the audio samples
      // (We'll generate a single C4 note with a sine wave, fading from left to right)
      constexpr double two_pi = 6.283185307179586476925286766559;
      constexpr double max_amplitude = 32760/2;  // "volume"

      double hz        = 8000;    // samples per second
      double frequency = f1;  // middle C
      double freq2 = f2;
      double seconds   = 0.04;      // time

      int N = hz * seconds;  // total number of samples
      for (int n = 0; n < N; n++)
      {
        double amplitude = (double)(n) / N * max_amplitude;
        double value     = (sin( (two_pi * n * frequency) / hz ) + sin ((two_pi*n*freq2)/hz)); ///float(2);
        write_word( f, (int)( max_amplitude  * value), 2 );
        write_word( f, (int)((max_amplitude) * value), 2 );
      }

      // (We'll need the final file size to fix the chunk sizes above)
      size_t file_length = f.tellp();

      // Fix the data chunk header to contain the data size
      f.seekp( data_chunk_pos + 4 );
      write_word( f, file_length - data_chunk_pos + 8 );

      // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
      f.seekp( 0 + 4 );
      write_word( f, file_length - 8, 4 );
}

void DtmfGenerator::generateNumber(char* number){
      ofstream f( "number.wav", ios::binary );

      // Write the file headers
      f << "RIFF----WAVEfmt ";     // (chunk size to be filled in later)
      write_word( f,     16, 4 );  // no extension data
      write_word( f,      1, 2 );  // PCM - integer samples
      write_word( f,      2, 2 );  // two channels (stereo file)
      write_word( f,   8000, 4 );  // samples per second (Hz)
      write_word( f,  32000, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
      write_word( f,      4, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
      write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)

      // Write the data chunk header
      size_t data_chunk_pos = f.tellp();
      f << "data----";  // (chunk size to be filled in later)

      // Write the audio samples
      // (We'll generate a single C4 note with a sine wave, fading from left to right)
      constexpr double two_pi = 6.283185307179586476925286766559;
      constexpr double max_amplitude = 32760/2;  // "volume"

      double hz        = 8000;    // samples per second
      for(int i=0;i<10;i++){
          double frequency = getLowFrequency(number[i]);  // middle C
          double freq2 = getHighFrequency(number[i]);;
          double seconds   = 0.04;      // time

          int N = hz * seconds;  // total number of samples
          for (int n = 0; n < N; n++)
          {
            double amplitude = (double)(n) / N * max_amplitude;
            double value     = (sin( (two_pi * n * frequency) / hz ) + sin ((two_pi*n*freq2)/hz)); ///float(2);
            write_word( f, (int)( max_amplitude  * value), 2 );
            write_word( f, (int)((max_amplitude) * value), 2 );
          }
      }
      // (We'll need the final file size to fix the chunk sizes above)
      size_t file_length = f.tellp();

      // Fix the data chunk header to contain the data size
      f.seekp( data_chunk_pos + 4 );
      write_word( f, file_length - data_chunk_pos + 8 );

      // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
      f.seekp( 0 + 4 );
      write_word( f, file_length - 8, 4 );
}

int DtmfGenerator::getHighFrequency(char number){

    switch (number) {
    case '0':
        return 1336;
    case '*':
        return 1209;
    case '#':
        return 1477;
    case '1':
        return 1209;
    case '2':
        return 1336;
    case '3':
        return 1477;
    case '4':
        return 1209;
    case '5':
        return 1336;
    case '6':
        return 1477;
    case '7':
        return 1209;
    case '8':
        return 1336;
    case '9':
        return 1477;
    case 'a':
        return 1633;
    case 'b':
        return 1633;
    case 'c':
        return 1633;
    case 'd':
        return 1633;
    default:
        break;
    }
}

int DtmfGenerator::getLowFrequency(char number){
    switch (number) {
    case '0':
        return 941;
    case '*':
        return 941;
    case '#':
        return 941;
    case '1':
        return 697;
    case '2':
        return 697;
    case '3':
        return 697;
    case '4':
        return 770;
    case '5':
        return 770;
    case '6':
        return 770;
    case '7':
        return 852;
    case '8':
        return 852;
    case '9':
        return 852;
    case 'a':
        return 697;
    case 'b':
        return 770;
    case 'c':
        return 852;
    case 'd':
        return 941;
    default:
        break;
    }
}

string DtmfGenerator::getname(char number){
    switch (number) {
    case '0':
        return "0.wav";
    case '*':
        return "iz.wav";
    case '#':
        return "hash.wav";
    case '1':
        return "1.wav";
    case '2':
        return "2.wav";
    case '3':
        return "3.wav";
    case '4':
        return "4.wav";
    case '5':
        return "5.wav";
    case '6':
        return "6.wav";
    case '7':
        return "7.wav";
    case '8':
        return "8.wav";
    case '9':
        return "9.wav";
    case 'a':
        return "a.wav";
    case 'b':
        return "b.wav";
    case 'c':
        return "c.wav";
    case 'd':
        return "d.wav";
    default:
        break;
    }
}

void  DtmfGenerator::initTones(){
    char tones[]  = {'0','1','2','3','4','5','6','7','8','9','#','*','a','b','c','d'};
    for(int i = 0; i<16; i++){
        int f1 = getLowFrequency(tones[i]);
        int f2 = getHighFrequency(tones[i]);
        generateTone(f1,f2,getname(tones[i]));

    }
}
