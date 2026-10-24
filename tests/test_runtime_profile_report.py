import importlib.util
import json
import unittest
from pathlib import Path

path = Path(__file__).parents[1] / "scripts/analyze_runtime_profile.py"
spec = importlib.util.spec_from_file_location("analyze_runtime_profile", path)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class ProfileReportTests(unittest.TestCase):
    def record(self, frame=1, thread="2", calls=2):
        import json
        return json.dumps({"schema": 1, "session": "1", "thread": thread, "batch": 1,
                           "document": "3", "marker": "4", "time_seconds": frame / 30,
                           "frame": frame, "fps": 30, "root_calls": 1, "root_ms": 5,
                           "stages": [{"name": "morph.total", "calls": calls, "inclusive_ms": 7,
                                       "self_ms": 5, "max_ms": 5}]})

    def test_repeated_time_and_batches_merge_without_summing_maximum(self):
        result = module.summarize([self.record(), self.record(), self.record(frame=2)])
        self.assertEqual(result["buckets"], 2)
        self.assertEqual(result["stages"][0]["calls"], 6)
        self.assertEqual(result["stages"][0]["max_ms"], 5)
        self.assertEqual(result["stages"][0]["mean_self_ms_per_bucket"], 7.5)
        self.assertEqual(result["root_ms"], 15)

    def test_threads_stay_separate_and_filters_apply(self):
        result = module.summarize([self.record(), self.record(thread="9"), self.record(frame=2)], frame_max=1)
        self.assertEqual(result["buckets"], 2)
        self.assertEqual(len(result["contexts"]), 2)
        self.assertEqual(module.summarize([self.record()], document="missing")["buckets"], 0)

    def test_console_prefix_and_corrupt_json(self):
        self.assertEqual(module.summarize(["other log", "[CMT][Profile] " + self.record()])["buckets"], 1)
        with self.assertRaisesRegex(ValueError, "profile line 2"):
            module.summarize([self.record(), "{broken"])
        for field, value in [('root_calls', -1), ('time_seconds', float('nan'))]:
            record = json.loads(self.record())
            record[field] = value
            with self.subTest(field=field), self.assertRaises(ValueError):
                module.summarize([json.dumps(record)])


if __name__ == "__main__":
    unittest.main()
