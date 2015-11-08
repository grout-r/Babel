######################################################################
# Automatically generated by qmake (2.01a) sam. nov. 7 18:57:31 2015
######################################################################

TEMPLATE = app
TARGET = babelcli

QMAKE_CXXFLAGS += -std=c++11

DEPENDPATH += . \
              CMakeFiles \
              CommonIncludes \
              opus-1.1 \
              Client/includes \
              Client/src \
              opus-1.1/celt \
              opus-1.1/doc \
              opus-1.1/include \
              opus-1.1/silk \
              opus-1.1/src \
              opus-1.1/tests \
              opus-1.1/win32 \
              portaudio/examples \
              portaudio/include \
              portaudio/pablio \
              portaudio/qa \
              portaudio/test \
              Server/includes \
              Server/src \
              CMakeFiles/2.8.12.2/CompilerIdC \
              CMakeFiles/2.8.12.2/CompilerIdCXX \
              CMakeFiles/3.4.0-rc2/CompilerIdC \
              CMakeFiles/3.4.0-rc2/CompilerIdCXX \
              opus-1.1/celt/arm \
              opus-1.1/celt/tests \
              opus-1.1/celt/x86 \
              opus-1.1/silk/arm \
              opus-1.1/silk/fixed \
              opus-1.1/silk/float \
              portaudio/src/common \
              portaudio/bindings/cpp/example \
              portaudio/qa/loopback/src \
              portaudio/src/hostapi/alsa \
              portaudio/src/hostapi/asihpi \
              portaudio/src/hostapi/asio \
              portaudio/src/hostapi/coreaudio \
              portaudio/src/hostapi/dsound \
              portaudio/src/hostapi/jack \
              portaudio/src/hostapi/oss \
              portaudio/src/hostapi/skeleton \
              portaudio/src/hostapi/wasapi \
              portaudio/src/hostapi/wdmks \
              portaudio/src/hostapi/wmme \
              portaudio/src/os/unix \
              portaudio/src/os/win \
              portaudio/bindings/cpp/include/portaudiocpp \
              portaudio/bindings/cpp/source/portaudiocpp \
              portaudio/bindings/java/c/src \
              portaudio/src/hostapi/wasapi/mingw-include
INCLUDEPATH += . \
               CommonIncludes \
               Client/includes \
               Server/includes \
               opus-1.1/include \
               portaudio/include \
               opus-1.1 \
               opus-1.1/celt \
               opus-1.1/celt/arm \
               opus-1.1/celt/x86 \
               opus-1.1/silk \
               opus-1.1/silk/arm \
               opus-1.1/silk/fixed \
               opus-1.1/silk/float \
               opus-1.1/src \
               opus-1.1/tests \
               portaudio/src/common \
               portaudio/pablio \
               portaudio/qa/loopback/src \
               portaudio/src/os/unix \
               portaudio/src/hostapi/asio \
               portaudio/src/os/win \
               portaudio/src/hostapi/coreaudio \
               portaudio/src/hostapi/dsound \
               portaudio/src/hostapi/wasapi/mingw-include \
               portaudio/bindings/java/c/src

# Input
HEADERS += CommonIncludes/ClientPacket.h \
           CommonIncludes/NetworkAPI.h \
           CommonIncludes/ServerPacket.h \
           CommonIncludes/UNetworkAPI.h \
           CommonIncludes/WNetworkAPI.h \
           opus-1.1/config.h \
           Client/includes/AudioCodec.h \
           Client/includes/AudioController.h \
           Client/includes/AudioInput.h \
           Client/includes/AudioOutput.h \
           Client/includes/Core.h \
           Client/includes/GUI.h \
           Client/includes/IAudio.hh \
           Client/includes/ICodec.h \
           Client/includes/IMutex.h \
           Client/includes/InterClientCom.h \
           Client/includes/IThread.h \
           Client/includes/SafeQueue.h \
           Client/includes/ScopedLock.h \
           Client/includes/ServerLink.h \
           Client/includes/Sound.hpp \
           Client/includes/Transformer.h \
           Client/includes/UMutex.h \
           Client/includes/UNetworkAPI.h \
           Client/includes/UserInterfaceController.h \
           Client/includes/UThread.h \
           Client/includes/WindowsNetworkDefines.h \
           Client/includes/WMutex.h \
           Client/includes/WThread.h \
           opus-1.1/celt/_kiss_fft_guts.h \
           opus-1.1/celt/arch.h \
           opus-1.1/celt/bands.h \
           opus-1.1/celt/celt.h \
           opus-1.1/celt/celt_lpc.h \
           opus-1.1/celt/cpu_support.h \
           opus-1.1/celt/cwrs.h \
           opus-1.1/celt/ecintrin.h \
           opus-1.1/celt/entcode.h \
           opus-1.1/celt/entdec.h \
           opus-1.1/celt/entenc.h \
           opus-1.1/celt/fixed_debug.h \
           opus-1.1/celt/fixed_generic.h \
           opus-1.1/celt/float_cast.h \
           opus-1.1/celt/kiss_fft.h \
           opus-1.1/celt/laplace.h \
           opus-1.1/celt/mathops.h \
           opus-1.1/celt/mdct.h \
           opus-1.1/celt/mfrngcod.h \
           opus-1.1/celt/modes.h \
           opus-1.1/celt/os_support.h \
           opus-1.1/celt/pitch.h \
           opus-1.1/celt/quant_bands.h \
           opus-1.1/celt/rate.h \
           opus-1.1/celt/stack_alloc.h \
           opus-1.1/celt/static_modes_fixed.h \
           opus-1.1/celt/static_modes_float.h \
           opus-1.1/celt/vq.h \
           opus-1.1/include/opus.h \
           opus-1.1/include/opus_custom.h \
           opus-1.1/include/opus_defines.h \
           opus-1.1/include/opus_multistream.h \
           opus-1.1/include/opus_types.h \
           opus-1.1/silk/API.h \
           opus-1.1/silk/control.h \
           opus-1.1/silk/debug.h \
           opus-1.1/silk/define.h \
           opus-1.1/silk/errors.h \
           opus-1.1/silk/Inlines.h \
           opus-1.1/silk/MacroCount.h \
           opus-1.1/silk/MacroDebug.h \
           opus-1.1/silk/macros.h \
           opus-1.1/silk/main.h \
           opus-1.1/silk/pitch_est_defines.h \
           opus-1.1/silk/PLC.h \
           opus-1.1/silk/resampler_private.h \
           opus-1.1/silk/resampler_rom.h \
           opus-1.1/silk/resampler_structs.h \
           opus-1.1/silk/SigProc_FIX.h \
           opus-1.1/silk/structs.h \
           opus-1.1/silk/tables.h \
           opus-1.1/silk/tuning_parameters.h \
           opus-1.1/silk/typedef.h \
           opus-1.1/src/analysis.h \
           opus-1.1/src/mlp.h \
           opus-1.1/src/opus_private.h \
           opus-1.1/src/tansig_table.h \
           opus-1.1/tests/test_opus_common.h \
           opus-1.1/win32/config.h \
           portaudio/include/pa_asio.h \
           portaudio/include/pa_jack.h \
           portaudio/include/pa_linux_alsa.h \
           portaudio/include/pa_mac_core.h \
           portaudio/include/pa_win_ds.h \
           portaudio/include/pa_win_wasapi.h \
           portaudio/include/pa_win_waveformat.h \
           portaudio/include/pa_win_wdmks.h \
           portaudio/include/pa_win_wmme.h \
           portaudio/include/portaudio.h \
           portaudio/pablio/pablio.h \
           Server/includes/ClientBase.h \
           Server/includes/ClientDataHandler.h \
           Server/includes/ClientRuntime.h \
           Server/includes/IClientData.h \
           Server/includes/NetworkDefines.h \
           Server/includes/Server.h \
           Server/includes/XMLParser.h \
           opus-1.1/celt/arm/armcpu.h \
           opus-1.1/celt/arm/fixed_armv4.h \
           opus-1.1/celt/arm/fixed_armv5e.h \
           opus-1.1/celt/arm/kiss_fft_armv4.h \
           opus-1.1/celt/arm/kiss_fft_armv5e.h \
           opus-1.1/celt/arm/pitch_arm.h \
           opus-1.1/celt/x86/pitch_sse.h \
           opus-1.1/silk/arm/macros_armv4.h \
           opus-1.1/silk/arm/macros_armv5e.h \
           opus-1.1/silk/arm/SigProc_FIX_armv4.h \
           opus-1.1/silk/arm/SigProc_FIX_armv5e.h \
           opus-1.1/silk/fixed/main_FIX.h \
           opus-1.1/silk/fixed/structs_FIX.h \
           opus-1.1/silk/float/main_FLP.h \
           opus-1.1/silk/float/SigProc_FLP.h \
           opus-1.1/silk/float/structs_FLP.h \
           portaudio/src/common/pa_allocation.h \
           portaudio/src/common/pa_converters.h \
           portaudio/src/common/pa_cpuload.h \
           portaudio/src/common/pa_debugprint.h \
           portaudio/src/common/pa_dither.h \
           portaudio/src/common/pa_endianness.h \
           portaudio/src/common/pa_hostapi.h \
           portaudio/src/common/pa_memorybarrier.h \
           portaudio/src/common/pa_process.h \
           portaudio/src/common/pa_ringbuffer.h \
           portaudio/src/common/pa_stream.h \
           portaudio/src/common/pa_trace.h \
           portaudio/src/common/pa_types.h \
           portaudio/src/common/pa_util.h \
           portaudio/qa/loopback/src/audio_analyzer.h \
           portaudio/qa/loopback/src/biquad_filter.h \
           portaudio/qa/loopback/src/paqa_tools.h \
           portaudio/qa/loopback/src/qa_tools.h \
           portaudio/qa/loopback/src/test_audio_analyzer.h \
           portaudio/qa/loopback/src/write_wav.h \
           portaudio/src/hostapi/asio/iasiothiscallresolver.h \
           portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.h \
           portaudio/src/hostapi/coreaudio/pa_mac_core_internal.h \
           portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.h \
           portaudio/src/hostapi/dsound/pa_win_ds_dynlink.h \
           portaudio/src/os/unix/pa_unix_util.h \
           portaudio/src/os/win/pa_win_coinitialize.h \
           portaudio/src/os/win/pa_win_wdmks_utils.h \
           portaudio/src/os/win/pa_x86_plain_converters.h \
           portaudio/bindings/cpp/include/portaudiocpp/AsioDeviceAdapter.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/AutoSystem.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/BlockingStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/CallbackInterface.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/CallbackStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/CFunCallbackStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/CppFunCallbackStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/Device.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/DirectionSpecificStreamParameters.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/Exception.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/HostApi.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/InterfaceCallbackStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/MemFunCallbackStream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/PortAudioCpp.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/SampleDataFormat.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/Stream.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/StreamParameters.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/System.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/SystemDeviceIterator.hxx \
           portaudio/bindings/cpp/include/portaudiocpp/SystemHostApiIterator.hxx \
           portaudio/bindings/java/c/src/com_portaudio_BlockingStream.h \
           portaudio/bindings/java/c/src/com_portaudio_PortAudio.h \
           portaudio/bindings/java/c/src/jpa_tools.h \
           portaudio/src/hostapi/wasapi/mingw-include/audioclient.h \
           portaudio/src/hostapi/wasapi/mingw-include/AudioSessionTypes.h \
           portaudio/src/hostapi/wasapi/mingw-include/devicetopology.h \
           portaudio/src/hostapi/wasapi/mingw-include/endpointvolume.h \
           portaudio/src/hostapi/wasapi/mingw-include/functiondiscoverykeys.h \
           portaudio/src/hostapi/wasapi/mingw-include/FunctionDiscoveryKeys_devpkey.h \
           portaudio/src/hostapi/wasapi/mingw-include/ks.h \
           portaudio/src/hostapi/wasapi/mingw-include/ksguid.h \
           portaudio/src/hostapi/wasapi/mingw-include/ksmedia.h \
           portaudio/src/hostapi/wasapi/mingw-include/ksproxy.h \
           portaudio/src/hostapi/wasapi/mingw-include/ksuuids.h \
           portaudio/src/hostapi/wasapi/mingw-include/mmdeviceapi.h \
           portaudio/src/hostapi/wasapi/mingw-include/propidl.h \
           portaudio/src/hostapi/wasapi/mingw-include/propkey.h \
           portaudio/src/hostapi/wasapi/mingw-include/propkeydef.h \
           portaudio/src/hostapi/wasapi/mingw-include/propsys.h \
           portaudio/src/hostapi/wasapi/mingw-include/rpcsal.h \
           portaudio/src/hostapi/wasapi/mingw-include/sal.h \
           portaudio/src/hostapi/wasapi/mingw-include/sdkddkver.h \
           portaudio/src/hostapi/wasapi/mingw-include/shtypes.h \
           portaudio/src/hostapi/wasapi/mingw-include/structuredquery.h \
           opus-1.1/celt/entenc.c \
           opus-1.1/celt/entdec.c \
           opus-1.1/celt/entcode.c \
           opus-1.1/celt/cwrs.c \
           opus-1.1/celt/mathops.c \
           opus-1.1/celt/kiss_fft.c \
           opus-1.1/celt/laplace.c \
           opus-1.1/celt/bands.c \
           opus-1.1/celt/quant_bands.c \
           opus-1.1/celt/vq.c \
           opus-1.1/celt/mdct.c
SOURCES += BabelClient_automoc.cpp \
           CMakeFiles/feature_tests.c \
           CMakeFiles/feature_tests.cxx \
           CommonIncludes/UNetworkAPI.cpp \
           CommonIncludes/WNetworkAPI.cpp \
           Client/src/AudioCodec.cpp \
           Client/src/AudioController.cpp \
           Client/src/AudioInput.cpp \
           Client/src/AudiOutput.cpp \
           Client/src/Core.cpp \
           Client/src/GUI.cpp \
           Client/src/InterClientCom.cpp \
           Client/src/main.cpp \
           Client/src/ServerLink.cpp \
           Client/src/UserInterfaceController.cpp \
           opus-1.1/celt/bands.c \
           opus-1.1/celt/celt.c \
           opus-1.1/celt/celt_decoder.c \
           opus-1.1/celt/celt_encoder.c \
           opus-1.1/celt/celt_lpc.c \
           opus-1.1/celt/cwrs.c \
           opus-1.1/celt/entcode.c \
           opus-1.1/celt/entdec.c \
           opus-1.1/celt/entenc.c \
           opus-1.1/celt/kiss_fft.c \
           opus-1.1/celt/laplace.c \
           opus-1.1/celt/mathops.c \
           opus-1.1/celt/mdct.c \
           opus-1.1/celt/modes.c \
           opus-1.1/celt/opus_custom_demo.c \
           opus-1.1/celt/pitch.c \
           opus-1.1/celt/quant_bands.c \
           opus-1.1/celt/rate.c \
           opus-1.1/celt/vq.c \
           opus-1.1/doc/trivial_example.c \
           opus-1.1/silk/A2NLSF.c \
           opus-1.1/silk/ana_filt_bank_1.c \
           opus-1.1/silk/biquad_alt.c \
           opus-1.1/silk/bwexpander.c \
           opus-1.1/silk/bwexpander_32.c \
           opus-1.1/silk/check_control_input.c \
           opus-1.1/silk/CNG.c \
           opus-1.1/silk/code_signs.c \
           opus-1.1/silk/control_audio_bandwidth.c \
           opus-1.1/silk/control_codec.c \
           opus-1.1/silk/control_SNR.c \
           opus-1.1/silk/debug.c \
           opus-1.1/silk/dec_API.c \
           opus-1.1/silk/decode_core.c \
           opus-1.1/silk/decode_frame.c \
           opus-1.1/silk/decode_indices.c \
           opus-1.1/silk/decode_parameters.c \
           opus-1.1/silk/decode_pitch.c \
           opus-1.1/silk/decode_pulses.c \
           opus-1.1/silk/decoder_set_fs.c \
           opus-1.1/silk/enc_API.c \
           opus-1.1/silk/encode_indices.c \
           opus-1.1/silk/encode_pulses.c \
           opus-1.1/silk/gain_quant.c \
           opus-1.1/silk/HP_variable_cutoff.c \
           opus-1.1/silk/init_decoder.c \
           opus-1.1/silk/init_encoder.c \
           opus-1.1/silk/inner_prod_aligned.c \
           opus-1.1/silk/interpolate.c \
           opus-1.1/silk/lin2log.c \
           opus-1.1/silk/log2lin.c \
           opus-1.1/silk/LP_variable_cutoff.c \
           opus-1.1/silk/LPC_analysis_filter.c \
           opus-1.1/silk/LPC_inv_pred_gain.c \
           opus-1.1/silk/NLSF2A.c \
           opus-1.1/silk/NLSF_decode.c \
           opus-1.1/silk/NLSF_del_dec_quant.c \
           opus-1.1/silk/NLSF_encode.c \
           opus-1.1/silk/NLSF_stabilize.c \
           opus-1.1/silk/NLSF_unpack.c \
           opus-1.1/silk/NLSF_VQ.c \
           opus-1.1/silk/NLSF_VQ_weights_laroia.c \
           opus-1.1/silk/NSQ.c \
           opus-1.1/silk/NSQ_del_dec.c \
           opus-1.1/silk/pitch_est_tables.c \
           opus-1.1/silk/PLC.c \
           opus-1.1/silk/process_NLSFs.c \
           opus-1.1/silk/quant_LTP_gains.c \
           opus-1.1/silk/resampler.c \
           opus-1.1/silk/resampler_down2.c \
           opus-1.1/silk/resampler_down2_3.c \
           opus-1.1/silk/resampler_private_AR2.c \
           opus-1.1/silk/resampler_private_down_FIR.c \
           opus-1.1/silk/resampler_private_IIR_FIR.c \
           opus-1.1/silk/resampler_private_up2_HQ.c \
           opus-1.1/silk/resampler_rom.c \
           opus-1.1/silk/shell_coder.c \
           opus-1.1/silk/sigm_Q15.c \
           opus-1.1/silk/sort.c \
           opus-1.1/silk/stereo_decode_pred.c \
           opus-1.1/silk/stereo_encode_pred.c \
           opus-1.1/silk/stereo_find_predictor.c \
           opus-1.1/silk/stereo_LR_to_MS.c \
           opus-1.1/silk/stereo_MS_to_LR.c \
           opus-1.1/silk/stereo_quant_pred.c \
           opus-1.1/silk/sum_sqr_shift.c \
           opus-1.1/silk/table_LSF_cos.c \
           opus-1.1/silk/tables_gain.c \
           opus-1.1/silk/tables_LTP.c \
           opus-1.1/silk/tables_NLSF_CB_NB_MB.c \
           opus-1.1/silk/tables_NLSF_CB_WB.c \
           opus-1.1/silk/tables_other.c \
           opus-1.1/silk/tables_pitch_lag.c \
           opus-1.1/silk/tables_pulses_per_block.c \
           opus-1.1/silk/VAD.c \
           opus-1.1/silk/VQ_WMat_EC.c \
           opus-1.1/src/analysis.c \
           opus-1.1/src/mlp.c \
           opus-1.1/src/mlp_data.c \
           opus-1.1/src/opus.c \
           opus-1.1/src/opus_compare.c \
           opus-1.1/src/opus_decoder.c \
           opus-1.1/src/opus_demo.c \
           opus-1.1/src/opus_encoder.c \
           opus-1.1/src/opus_multistream.c \
           opus-1.1/src/opus_multistream_decoder.c \
           opus-1.1/src/opus_multistream_encoder.c \
           opus-1.1/src/repacketizer.c \
           opus-1.1/src/repacketizer_demo.c \
           opus-1.1/tests/test_opus_api.c \
           opus-1.1/tests/test_opus_decode.c \
           opus-1.1/tests/test_opus_encode.c \
           opus-1.1/tests/test_opus_padding.c \
           portaudio/examples/pa_devs.c \
           portaudio/examples/pa_fuzz.c \
           portaudio/examples/paex_mono_asio_channel_select.c \
           portaudio/examples/paex_ocean_shore.c \
           portaudio/examples/paex_pink.c \
           portaudio/examples/paex_read_write_wire.c \
           portaudio/examples/paex_record.c \
           portaudio/examples/paex_record_file.c \
           portaudio/examples/paex_saw.c \
           portaudio/examples/paex_sine.c \
           portaudio/examples/paex_sine_c++.cpp \
           portaudio/examples/paex_wmme_ac3.c \
           portaudio/examples/paex_wmme_surround.c \
           portaudio/examples/paex_write_sine.c \
           portaudio/examples/paex_write_sine_nonint.c \
           portaudio/pablio/pablio.c \
           portaudio/pablio/test_rw.c \
           portaudio/pablio/test_rw_echo.c \
           portaudio/pablio/test_w_saw.c \
           portaudio/pablio/test_w_saw8.c \
           portaudio/qa/paqa_devs.c \
           portaudio/qa/paqa_errs.c \
           portaudio/qa/paqa_latency.c \
           portaudio/test/pa_minlat.c \
           portaudio/test/patest1.c \
           portaudio/test/patest_buffer.c \
           portaudio/test/patest_callbackstop.c \
           portaudio/test/patest_clip.c \
           portaudio/test/patest_converters.c \
           portaudio/test/patest_dither.c \
           portaudio/test/patest_dsound_find_best_latency_params.c \
           portaudio/test/patest_dsound_low_level_latency_params.c \
           portaudio/test/patest_dsound_surround.c \
           portaudio/test/patest_hang.c \
           portaudio/test/patest_in_overflow.c \
           portaudio/test/patest_jack_wasapi.c \
           portaudio/test/patest_latency.c \
           portaudio/test/patest_leftright.c \
           portaudio/test/patest_longsine.c \
           portaudio/test/patest_many.c \
           portaudio/test/patest_maxsines.c \
           portaudio/test/patest_mono.c \
           portaudio/test/patest_multi_sine.c \
           portaudio/test/patest_out_underflow.c \
           portaudio/test/patest_prime.c \
           portaudio/test/patest_read_record.c \
           portaudio/test/patest_ringmix.c \
           portaudio/test/patest_sine8.c \
           portaudio/test/patest_sine_channelmaps.c \
           portaudio/test/patest_sine_formats.c \
           portaudio/test/patest_sine_srate.c \
           portaudio/test/patest_sine_time.c \
           portaudio/test/patest_start_stop.c \
           portaudio/test/patest_stop.c \
           portaudio/test/patest_stop_playout.c \
           portaudio/test/patest_suggested_vs_streaminfo_latency.c \
           portaudio/test/patest_sync.c \
           portaudio/test/patest_timing.c \
           portaudio/test/patest_toomanysines.c \
           portaudio/test/patest_two_rates.c \
           portaudio/test/patest_underflow.c \
           portaudio/test/patest_wire.c \
           portaudio/test/patest_wmme_find_best_latency_params.c \
           portaudio/test/patest_wmme_low_level_latency_params.c \
           portaudio/test/patest_write_stop.c \
           CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.c \
           CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           CMakeFiles/3.4.0-rc2/CompilerIdC/CMakeCCompilerId.c \
           CMakeFiles/3.4.0-rc2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           opus-1.1/celt/arm/arm_celt_map.c \
           opus-1.1/celt/arm/armcpu.c \
           opus-1.1/celt/tests/test_unit_cwrs32.c \
           opus-1.1/celt/tests/test_unit_dft.c \
           opus-1.1/celt/tests/test_unit_entropy.c \
           opus-1.1/celt/tests/test_unit_laplace.c \
           opus-1.1/celt/tests/test_unit_mathops.c \
           opus-1.1/celt/tests/test_unit_mdct.c \
           opus-1.1/celt/tests/test_unit_rotation.c \
           opus-1.1/celt/tests/test_unit_types.c \
           opus-1.1/silk/fixed/apply_sine_window_FIX.c \
           opus-1.1/silk/fixed/autocorr_FIX.c \
           opus-1.1/silk/fixed/burg_modified_FIX.c \
           opus-1.1/silk/fixed/corrMatrix_FIX.c \
           opus-1.1/silk/fixed/encode_frame_FIX.c \
           opus-1.1/silk/fixed/find_LPC_FIX.c \
           opus-1.1/silk/fixed/find_LTP_FIX.c \
           opus-1.1/silk/fixed/find_pitch_lags_FIX.c \
           opus-1.1/silk/fixed/find_pred_coefs_FIX.c \
           opus-1.1/silk/fixed/k2a_FIX.c \
           opus-1.1/silk/fixed/k2a_Q16_FIX.c \
           opus-1.1/silk/fixed/LTP_analysis_filter_FIX.c \
           opus-1.1/silk/fixed/LTP_scale_ctrl_FIX.c \
           opus-1.1/silk/fixed/noise_shape_analysis_FIX.c \
           opus-1.1/silk/fixed/pitch_analysis_core_FIX.c \
           opus-1.1/silk/fixed/prefilter_FIX.c \
           opus-1.1/silk/fixed/process_gains_FIX.c \
           opus-1.1/silk/fixed/regularize_correlations_FIX.c \
           opus-1.1/silk/fixed/residual_energy16_FIX.c \
           opus-1.1/silk/fixed/residual_energy_FIX.c \
           opus-1.1/silk/fixed/schur64_FIX.c \
           opus-1.1/silk/fixed/schur_FIX.c \
           opus-1.1/silk/fixed/solve_LS_FIX.c \
           opus-1.1/silk/fixed/vector_ops_FIX.c \
           opus-1.1/silk/fixed/warped_autocorrelation_FIX.c \
           opus-1.1/silk/float/apply_sine_window_FLP.c \
           opus-1.1/silk/float/autocorrelation_FLP.c \
           opus-1.1/silk/float/burg_modified_FLP.c \
           opus-1.1/silk/float/bwexpander_FLP.c \
           opus-1.1/silk/float/corrMatrix_FLP.c \
           opus-1.1/silk/float/encode_frame_FLP.c \
           opus-1.1/silk/float/energy_FLP.c \
           opus-1.1/silk/float/find_LPC_FLP.c \
           opus-1.1/silk/float/find_LTP_FLP.c \
           opus-1.1/silk/float/find_pitch_lags_FLP.c \
           opus-1.1/silk/float/find_pred_coefs_FLP.c \
           opus-1.1/silk/float/inner_product_FLP.c \
           opus-1.1/silk/float/k2a_FLP.c \
           opus-1.1/silk/float/levinsondurbin_FLP.c \
           opus-1.1/silk/float/LPC_analysis_filter_FLP.c \
           opus-1.1/silk/float/LPC_inv_pred_gain_FLP.c \
           opus-1.1/silk/float/LTP_analysis_filter_FLP.c \
           opus-1.1/silk/float/LTP_scale_ctrl_FLP.c \
           opus-1.1/silk/float/noise_shape_analysis_FLP.c \
           opus-1.1/silk/float/pitch_analysis_core_FLP.c \
           opus-1.1/silk/float/prefilter_FLP.c \
           opus-1.1/silk/float/process_gains_FLP.c \
           opus-1.1/silk/float/regularize_correlations_FLP.c \
           opus-1.1/silk/float/residual_energy_FLP.c \
           opus-1.1/silk/float/scale_copy_vector_FLP.c \
           opus-1.1/silk/float/scale_vector_FLP.c \
           opus-1.1/silk/float/schur_FLP.c \
           opus-1.1/silk/float/solve_LS_FLP.c \
           opus-1.1/silk/float/sort_FLP.c \
           opus-1.1/silk/float/warped_autocorrelation_FLP.c \
           opus-1.1/silk/float/wrappers_FLP.c \
           portaudio/src/common/pa_allocation.c \
           portaudio/src/common/pa_converters.c \
           portaudio/src/common/pa_cpuload.c \
           portaudio/src/common/pa_debugprint.c \
           portaudio/src/common/pa_dither.c \
           portaudio/src/common/pa_front.c \
           portaudio/src/common/pa_process.c \
           portaudio/src/common/pa_ringbuffer.c \
           portaudio/src/common/pa_stream.c \
           portaudio/src/common/pa_trace.c \
           portaudio/bindings/cpp/example/devs.cxx \
           portaudio/bindings/cpp/example/sine.cxx \
           portaudio/qa/loopback/src/audio_analyzer.c \
           portaudio/qa/loopback/src/biquad_filter.c \
           portaudio/qa/loopback/src/paqa.c \
           portaudio/qa/loopback/src/paqa_tools.c \
           portaudio/qa/loopback/src/test_audio_analyzer.c \
           portaudio/qa/loopback/src/write_wav.c \
           portaudio/src/hostapi/alsa/pa_linux_alsa.c \
           portaudio/src/hostapi/asihpi/pa_linux_asihpi.c \
           portaudio/src/hostapi/asio/iasiothiscallresolver.cpp \
           portaudio/src/hostapi/asio/pa_asio.cpp \
           portaudio/src/hostapi/coreaudio/pa_mac_core.c \
           portaudio/src/hostapi/coreaudio/pa_mac_core_blocking.c \
           portaudio/src/hostapi/coreaudio/pa_mac_core_old.c \
           portaudio/src/hostapi/coreaudio/pa_mac_core_utilities.c \
           portaudio/src/hostapi/dsound/pa_win_ds.c \
           portaudio/src/hostapi/dsound/pa_win_ds_dynlink.c \
           portaudio/src/hostapi/jack/pa_jack.c \
           portaudio/src/hostapi/oss/pa_unix_oss.c \
           portaudio/src/hostapi/oss/recplay.c \
           portaudio/src/hostapi/skeleton/pa_hostapi_skeleton.c \
           portaudio/src/hostapi/wasapi/pa_win_wasapi.c \
           portaudio/src/hostapi/wdmks/pa_win_wdmks.c \
           portaudio/src/hostapi/wmme/pa_win_wmme.c \
           portaudio/src/os/unix/pa_unix_hostapis.c \
           portaudio/src/os/unix/pa_unix_util.c \
           portaudio/src/os/win/pa_win_coinitialize.c \
           portaudio/src/os/win/pa_win_hostapis.c \
           portaudio/src/os/win/pa_win_util.c \
           portaudio/src/os/win/pa_win_waveformat.c \
           portaudio/src/os/win/pa_win_wdmks_utils.c \
           portaudio/src/os/win/pa_x86_plain_converters.c \
           portaudio/bindings/cpp/source/portaudiocpp/AsioDeviceAdapter.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/BlockingStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/CallbackInterface.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/CallbackStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/CFunCallbackStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/CppFunCallbackStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/Device.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/DirectionSpecificStreamParameters.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/Exception.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/HostApi.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/InterfaceCallbackStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/MemFunCallbackStream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/Stream.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/StreamParameters.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/System.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/SystemDeviceIterator.cxx \
           portaudio/bindings/cpp/source/portaudiocpp/SystemHostApiIterator.cxx \
           portaudio/bindings/java/c/src/com_portaudio_BlockingStream.c \
           portaudio/bindings/java/c/src/com_portaudio_PortAudio.c \
           portaudio/bindings/java/c/src/jpa_tools.c
