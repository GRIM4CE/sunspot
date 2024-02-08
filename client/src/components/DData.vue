<script setup lang="ts">
import type { PropType } from 'vue'
import type { LightDataObject } from "@/types/index"

defineProps({
    data: {
        type: Array as PropType<LightDataObject[]>,
        required: true
    } 
})
</script>

<template>
    <section  class="record-container">
        <div class="record" v-for="lightRecord in data" :key="JSON.stringify(lightRecord.timestamp)">
            {{ lightRecord.lux }}
            {{ lightRecord.timestamp }}
        </div>
    </section>
</template>

<style lang="scss">
    .record-container {
        display: flex;
    }
    
    .record {
        display: grid;
    }
</style>