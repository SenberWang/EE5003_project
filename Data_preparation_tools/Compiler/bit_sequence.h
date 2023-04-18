//
// Created by YLW20 on 2022/5/19.
//

#ifndef CL_COMPILER_BIT_SEQUENCE_H
#define CL_COMPILER_BIT_SEQUENCE_H

#include <string>
#include <bitset>
#include <algorithm>
#include <exception>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include "num_magic.h"
#include "bug_message.h"

class bit_sequence_construct_exception: std::exception{
};

template<unsigned N>
class bit_sequence{
public:
    std::bitset<N> bits; // bits[0] LSB --- bits[N-1] MSB/SIGN

    bit_sequence(){
        ;
    }

    bit_sequence(uint_64 input){
        for(int i=0; i<=N-1; i++){
            bits[i] = input % 2;
            input = input >> 1;
        }
    }

    bit_sequence(std::string str, bool sign = false){
        uint_64 data;
        if(str[0] == '#'){
            if (!bin_string2num("0b" + str.substr(1, str.length()-1), sign, data));
            else {
                std::cout << "Failed to convert string \"" + str + "\" to bit_sequence." << std::endl;
                throw bit_sequence_construct_exception{};
            }
        }
        else if(str[0] == '0' && str[1] == 'b') {
            if (!bin_string2num(str, sign, data));
            else {
                std::cout << "Failed to convert string \"" + str + "\" to bit_sequence." << std::endl;
                throw bit_sequence_construct_exception{};
            }
        }
        else if(str[0] == '0' && str[1] == 'x') {
            if (!hex_string2num(str, sign, data));
            else {
                ERROR(".");
                assert(0);
            }
        }
        else if(str[0] == 'd'){
            if(!dec_string2num(str.substr(1, str.length()-1), sign, data));
            else{
                std::cout << "Failed to convert string \"" + str + "\" to bit_sequence." << std::endl;
                throw bit_sequence_construct_exception{};
            }
        }
        else{
            if(!dec_string2num(str, sign, data));
            else{
                std::cout << "Failed to convert string \"" + str + "\" to bit_sequence. It is not"
                             "a valid binary/decimal/hexadecimal expression." << std::endl;
                throw bit_sequence_construct_exception{};
            }
        }
        for(int i=0; i<=N-1; i++){
            bits[i] = data % 2;
            data = data >> 1;
        }
    }

    template<unsigned M>
    bit_sequence<M> sub_bits(uint_8 lsb_idx, uint_8 msb_idx){
        bit_sequence<M> sub_bits;
        if(lsb_idx > N-1){
            ERROR("lsb_idx should not exceed N-1.\n    lsb_idx = %u, N - 1 = %u.\n", lsb_idx, N-1);
            throw bit_sequence_construct_exception{};
        }
        if(msb_idx > N-1){
            ERROR("msb_idx should not exceed N-1.\n    msb_idx = %u, N - 1 = %u.\n", msb_idx, N-1);
            throw bit_sequence_construct_exception{};
        }
        if(lsb_idx > msb_idx){
            ERROR("lsb_idx should not be large than msb_idx.\n    lsb_idx = %u, msb_idx = %u.\n", lsb_idx, msb_idx);
            throw bit_sequence_construct_exception{};
        }
        if(msb_idx-lsb_idx+1>M){
            WARNING("msb_idx - lsb_idx + 1 > M, there will be truncation.\n    msb_idx = %u, lsb_idx = %u, M = %u.\n", msb_idx, lsb_idx, M);
            throw bit_sequence_construct_exception{};
        }
        for(int i=0; i<=msb_idx-lsb_idx; i++){
            if(i <= M-1)
                sub_bits.bits[i] = bits[i+lsb_idx];
        }
        return sub_bits;
    }

    std::string to_dec_string(uint_8 dec_bits_num = std::ceil(N * std::log10(2)), bool sign = false){
        std::string dec_string;
        uint_64     u = 0;
        int_64      s = 0;
        if(sign){
            for(int i=0; i<=N-1; i++)
                s += ( (i!=N-1) ? (bits[i] << i) : (-(bits[i] << i)) );
            s = (s>0) ? s : -s;
            if( s > pow(10, dec_bits_num - 1) - 1)
                WARNING("There might be data truncation: %d exceed the range of %u dec-bits.\n", s, dec_bits_num);
            for(int i=0; i<=dec_bits_num-1; i++){
                dec_string += (char)(s%10 + 48);
                s /= 10;
            }
            if(bits[N-1]==1)
                dec_string += '-';
            std::reverse(dec_string.begin(), dec_string.end());
        }
        else{
            u = bits.to_ullong();
            if( u > pow(10, dec_bits_num) - 1)
                WARNING("There might be data truncation: %u exceed the range of %u dec-bits.\n", u, dec_bits_num);
            for(int i=0; i<=dec_bits_num-1; i++){
                dec_string += (char)(u%10 + 48);
                u /= 10;
            }
            std::reverse(dec_string.begin(), dec_string.end());
        }
        return dec_string;
    }

    std::string to_bin_string(uint_8 bin_bits_num = N, bool sign = false, bool hide_prefix = true){
        std::string bin_string;
        uint_64     u = bits.to_ullong();
        int_64      s = 0;
        for(int i=0; i<=N-1; i++)
            s += ( (i!=N-1) ? (bits[i] << i) : (-(bits[i] << i)) );
        s = (s>0) ? s : -s;
        uint_64 v = (sign) ? s : u;
        if ( sign && v > (pow(2, bin_bits_num-1) - 1) || (!sign) && v > (pow(2, bin_bits_num) - 1) )
            WARNING("There might be data truncation:?? %s will be truncated to %d bits.\n",
                    bits.to_string().c_str(), bin_bits_num);

        for(int i=0; i<=bin_bits_num-1; i++){
            if(i<=N-1)
                bin_string += (bits[i]) ? '1' : '0';
            else
                bin_string += sign ? (bits[i] ? '1' : '0') : '0';
        }
        if(!hide_prefix)
            bin_string += "b0";
        std::reverse(bin_string.begin(), bin_string.end());
        return bin_string;
    }

    std::string to_hex_string(uint_8 hex_bits_num = std::ceil(N/4.0), bool sign = false, bool hide_prefix = true){
        std::string hex_string;
        uint_64     u = bits.to_ullong();
        int_64      s = 0;
        for(int i=0; i<=N-1; i++)
            s += ( (i!=N-1) ? (bits[i] << i) : (-(bits[i] << i)) );
        s = (s>0) ? s : -s;
        uint_64 v = (sign) ? s : u;
        if ( sign && v > (pow(2, 4 * hex_bits_num-1) - 1) || (!sign) && v > (pow(2, 4 * hex_bits_num) - 1) )
            WARNING("There might be data truncation: %s will be truncated to %u hex-bits.\n",
                    bits.to_string().c_str(), hex_bits_num);
        std::bitset<64> extend_bits;
        for(int i=0; i<=63; i++){
            if(i<=N-1)
                extend_bits[i] = bits[i];
            else
                extend_bits[i] = (sign) ? bits[N-1] : 0;
        }
        //std::cout<<extend_bits.to_string()<<std::endl;
        for(int i=0; i<=hex_bits_num-1; i++){
            std::bitset<4> bits_seg;
            bits_seg[0] = extend_bits[4*i];
            bits_seg[1] = extend_bits[4*i+1];
            bits_seg[2] = extend_bits[4*i+2];
            bits_seg[3] = extend_bits[4*i+3];
            //std::cout<<bits_seg.to_string()<<std::endl;
            hex_string += num2hex_bit(bits_seg.to_ulong());
        }
        if(!hide_prefix)
            hex_string += "x0";
        std::reverse(hex_string.begin(), hex_string.end());
        return hex_string;
    }
};

#endif //CL_COMPILER_BIT_SEQUENCE_H
