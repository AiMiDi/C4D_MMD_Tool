    // Slowly rising goals expose discrete quarter/half floor backtracking.
    // The near-straight IK branch at earlier frames is a separate limitation:
    // inspect continuity only inside the stable branch (55..63), but protect
    // every frame's collision pairs and playback IK error over the whole sweep.
    libmmd::VMDFile floorBacktrack;
    floorBacktrack.m_motions.push_back(Key("センター", 0));
    for (uint32_t frame = 0; frame <= 100; ++frame)
        for (const std::string side : {"左", "右"})
        {
            auto key = Key(side + "足ＩＫ", frame);
            key.m_translate.y() = static_cast<float>(.15 + .002 * frame);
            floorBacktrack.m_motions.push_back(key);
        }
    const auto refinedFloor = Run(model, model, floorBacktrack, floorOnly); RequireResult(refinedFloor);
    const Motion floorBefore(refinedFloor.stages[5]), floorAfter(refinedFloor.stages[6]);
    for (uint32_t frame = 0; frame <= 100; ++frame)
    {
        const Pose incoming(rig, floorBefore, frame), adjusted(rig, floorAfter, frame);
        const auto originalDepths = LegPenetrations(incoming, pairs, floorOnly.collisionMargin);
        const auto adjustedDepths = LegPenetrations(adjusted, pairs, floorOnly.collisionMargin);
        for (size_t pair = 0; pair < pairs.size(); ++pair)
            Check(adjustedDepths[pair] <= std::max(originalDepths[pair], floorOnly.tolerance) + 2.e-6,
                "Refined floor step worsened a leg collision pair");
        for (const std::string side : {"左", "右"})
        {
            const int goal = rig.Find(side + "足ＩＫ"), ankle = rig.Find(side + "足首");
            Check((adjusted.positions[ankle] - adjusted.positions[goal]).norm() <=
                (incoming.positions[ankle] - incoming.positions[goal]).norm() + floorOnly.tolerance + 2.e-6,
                "Refined floor step bypassed the playback IK error guard");
            Vector correction = adjusted.positions[goal] - incoming.positions[goal];
            correction.y() = 0.;
            Check(correction.norm() < 2.e-6, "Floor refinement changed horizontal authored motion");
            if (frame >= 56 && frame <= 63)
                Check(std::abs(floorAfter.Sample(side + "足ＩＫ", frame).translation.y() -
                    floorAfter.Sample(side + "足ＩＫ", frame - 1).translation.y()) < .01,
                    "Discrete floor backtracking introduced a stair step");
        }
    }
