import { SimulationClock } from './clock/simulation-clock.js';
import { RP2040 } from './rp2040.js';
export class Simulator {
    constructor(clock = new SimulationClock()) {
        this.clock = clock;
        this.executeTimer = null;
        this.stopped = true;
        this.rp2040 = new RP2040(clock);
        this.rp2040.onBreak = () => this.stop();
    }
    execute() {
        const { rp2040, clock } = this;
        this.executeTimer = null;
        this.stopped = false;
        const cycleNanos = 1e9 / 125000000; // 125 MHz
        for (let i = 0; i < 1000000 && !this.stopped; i++) {
            if (rp2040.core.waiting) {
                const { nanosToNextAlarm } = clock;
                clock.tick(nanosToNextAlarm);
                i += nanosToNextAlarm / cycleNanos;
            }
            else {
                const cycles = rp2040.core.executeInstruction();
                clock.tick(cycles * cycleNanos);
            }
        }
        if (!this.stopped) {
            this.executeTimer = setTimeout(() => this.execute(), 0);
        }
    }
    stop() {
        this.stopped = true;
        if (this.executeTimer != null) {
            clearTimeout(this.executeTimer);
            this.executeTimer = null;
        }
    }
    get executing() {
        return !this.stopped;
    }
}
