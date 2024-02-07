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
    {{ data }}
</template>