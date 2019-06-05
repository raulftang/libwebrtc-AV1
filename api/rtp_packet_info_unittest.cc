/*
 *  Copyright (c) 2019 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "api/rtp_packet_infos.h"

#include "test/gmock.h"
#include "test/gtest.h"

namespace webrtc {

TEST(RtpPacketInfoTest, Ssrc) {
  const uint32_t value = 4038189233;

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_ssrc(value);
  EXPECT_EQ(rhs.ssrc(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.ssrc(), value);

  rhs = RtpPacketInfo(value, {}, {}, {}, {}, {});
  EXPECT_EQ(rhs.ssrc(), value);
}

TEST(RtpPacketInfoTest, Csrcs) {
  const std::vector<uint32_t> value = {4038189233, 3016333617, 1207992985};

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_csrcs(value);
  EXPECT_EQ(rhs.csrcs(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.csrcs(), value);

  rhs = RtpPacketInfo({}, value, {}, {}, {}, {});
  EXPECT_EQ(rhs.csrcs(), value);
}

TEST(RtpPacketInfoTest, SequenceNumber) {
  const uint16_t value = 20238;

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_sequence_number(value);
  EXPECT_EQ(rhs.sequence_number(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.sequence_number(), value);

  rhs = RtpPacketInfo({}, {}, value, {}, {}, {});
  EXPECT_EQ(rhs.sequence_number(), value);
}

TEST(RtpPacketInfoTest, RtpTimestamp) {
  const uint32_t value = 4038189233;

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_rtp_timestamp(value);
  EXPECT_EQ(rhs.rtp_timestamp(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.rtp_timestamp(), value);

  rhs = RtpPacketInfo({}, {}, {}, value, {}, {});
  EXPECT_EQ(rhs.rtp_timestamp(), value);
}

TEST(RtpPacketInfoTest, AudioLevel) {
  const absl::optional<uint8_t> value = 31;

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_audio_level(value);
  EXPECT_EQ(rhs.audio_level(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.audio_level(), value);

  rhs = RtpPacketInfo({}, {}, {}, {}, value, {});
  EXPECT_EQ(rhs.audio_level(), value);
}

TEST(RtpPacketInfoTest, ReceiveTimeMs) {
  const int64_t value = 8868963877546349045LL;

  RtpPacketInfo lhs;
  RtpPacketInfo rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs.set_receive_time_ms(value);
  EXPECT_EQ(rhs.receive_time_ms(), value);

  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);

  lhs = rhs;

  EXPECT_TRUE(lhs == rhs);
  EXPECT_FALSE(lhs != rhs);

  rhs = RtpPacketInfo();
  EXPECT_NE(rhs.receive_time_ms(), value);

  rhs = RtpPacketInfo({}, {}, {}, {}, {}, value);
  EXPECT_EQ(rhs.receive_time_ms(), value);
}

}  // namespace webrtc