GR_SWIG_BLOCK_MAGIC(skoli,echo_ff);

skoli_echo_ff_sptr skoli_make_echo_ff( unsigned int sample_rate, float delay, float echo_scaling);

class skoli_echo_ff : public gr_block
{
        private:
        skoli_echo_ff (unsigned int sample_rate, float delay, float echo_scaling);
};
